#include "PlayFair.h"

#include <iostream>
#include <algorithm>

namespace Solutions {

    std::string
    EncryptionTable::RemoveDuplicates(const std::string& str)
    {
        std::string res;
        res.reserve(str.size());
        auto it = str.cbegin();
        while( it != str.end() ){
            if( !alreadyInTable.count( *it ) ) {
                alreadyInTable.insert( *it );
                res += *it;
            }
            ++it;
        }
        return res;
    }
    
    void
    EncryptionTable::FillRest()
    {
        int i = 0;
        while( table.size() < 5*5 ) {
            // No risk for oor, since the alphabet is the same size as our maximum table size.
            char c = alphabet.at(i++);
            if( !alreadyInTable.count(c) ) {
                alreadyInTable.insert(c);
                table.push_back(c);
            }
        }
    }

    EncryptionTable::EncryptionTable( const std::string& keyword )
      : alreadyInTable()
    {
        table = RemoveDuplicates( ToUpperCopyAndReplaceJSkippingWhitespace( keyword ) );
        FillRest();
    }

    std::string
    EncryptionTable::EncryptDigraph( const std::string& digraph ) const
    {
        if( digraph.size() < 2 ){
            throw std::out_of_range("Size of digraph must be exactly 2!");
        }
        if( digraph == "XX" ){
            return "YY";
        }
        if( table.find_first_of( digraph ) == std::string::npos ){
            throw std::out_of_range("Digraph not found");
        }

        // Keep in mind that rows and columns are 0-indexed
        int rowOfFirst = (int)table.find( digraph.at(0) ) / 5;
        int columnOfFirst = (int)table.find( digraph.at(0) ) % 5;
        int rowOfSecond = (int)table.find( digraph.at(1) ) / 5;
        int columnOfSecond = (int)table.find( digraph.at(1) ) % 5;
        
        if( rowOfFirst != rowOfSecond && columnOfFirst != columnOfSecond ){
            return { table.at(rowOfFirst*5 + columnOfSecond),
                     table.at(rowOfSecond*5 + columnOfFirst)};
        }
        if( rowOfFirst == rowOfSecond ) {
            return { table.at(rowOfFirst*5 + ( (columnOfFirst + 1) % 5) ),
                     table.at(rowOfSecond*5 + ( (columnOfSecond + 1) % 5) )};
        }
        if( columnOfFirst == columnOfSecond ){
            return { table.at( ((rowOfFirst + 1) % 5)*5 + columnOfFirst ),
                     table.at( ((rowOfSecond + 1) % 5)*5 + columnOfSecond )};
        }
        throw std::invalid_argument("Unexpected argument: " + digraph);
    }


    DigraphList::DigraphList(const std::string& str)
    {
        if( str.size() < 2 ){
            if( str.size() == 1 ) {
                digraphs = str + 'X';
            }
            return;
        }

        digraphs = ToUpperCopyAndReplaceJSkippingWhitespace(str);
        InsertXBetweenConsecutiveDuplicates(digraphs);

        // If we ended up with an odd number of characters,
        // the last one is alone, so add an X
        if( digraphs.size() % 2 != 0 ){
            digraphs += 'X';
        }
    }

    void
    DigraphList::InsertXBetweenConsecutiveDuplicates( std::string& str )
    {
        for(int i = 0; i*2 + 1 < str.size(); ++i){
            if( str.at(i*2) == str.at(i*2 + 1) ){
                str.insert(i*2 + 1, "X");
            }
        }
    }

    std::string
    DigraphList::getDigraph(int i) const
    {
        if( i*2 + 1 >= digraphs.size() ){
            throw std::out_of_range("i exceeds size of DigraphList!");
        }
        return digraphs.substr(i*2, 2);
    }

    std::string
    ToUpperCopyAndReplaceJSkippingWhitespace(const std::string& str)
    {
        //! should be ok, but not 100% sure for wierd implementations of
        //! toupper or casing rules
        auto isSpace = [](char c) -> bool {
            return std::isspace(static_cast<unsigned char>(c));
        };
        auto toUpperAndReplaceJ = [](char c) -> char {
            return ( std::toupper(c) == 'J' ? 'I' : (char)std::toupper(c) );
        };

        std::string _ret;
        _ret.reserve(str.size());
        for(int i = 0; i < str.size(); ++i){
            char c = str.at(i);
            if( !isSpace(c) ){
                _ret += toUpperAndReplaceJ(c);
            }
        }
        return _ret;
    }

    std::string
    EncodeMessage(const std::string& in, const EncryptionTable& table)
    {
        std::string _ret;
        auto dgl = DigraphList(in);
        for(int i = 0; i < dgl.size(); ++i){
            _ret += table.EncryptDigraph( dgl.getDigraph(i) );
        }
        return _ret;
    }

    void PlayFair(std::istream& input, std::ostream& output)
    {
        std::string keyword, message, line;
        // This will break if we input something unexpected,
        // but I think it's fair to assume correct input format.
        while( !!std::getline(input, line, '\n' ) ) {
            int numLines = stoi( line );
            if( numLines <= 0 ){
                break;
            }
            if( !std::getline(input , keyword, '\n') ){
                std::cerr << "Failed to extract keyword" << std::endl;
                return;
            } else if( !message.empty() ) {
                // "Output a blank line between adjacent cases."
                // message should only be empty before first batch of testCases are read
                output << std::endl;
            }

            std::string results;
            EncryptionTable table(keyword);
            for( int i = 0; i < numLines && !!std::getline(input, message, '\n'); ++i ) {
                if( !results.empty() ) {
                    results += '\n';
                }
                results += EncodeMessage(message, table);
            }
            output << results << std::endl;
        }
    }
}

// int
// main( int argc, char* argv[] )
// {
//     Solutions::PlayFair(std::cin, std::cout);
//     return 0;
// }