#ifndef PLAY_FAIR_H
#define PLAY_FAIR_H

#include <string>
#include <ranges>
#include <unordered_set>

namespace Solutions {
    struct EncryptionTable
    {
      public:
        EncryptionTable() = default;
        explicit EncryptionTable( const std::string& keyword );

        std::string EncryptDigraph( const std::string& digraph ) const;
        std::string GetTable() const { return table; }

      private:
        std::string RemoveDuplicates(const std::string& str);
        void FillRest();

        std::string table;
        std::unordered_set<char> alreadyInTable;
        // Yay c++17
        inline static const std::string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    };

    struct DigraphList
    {
        explicit DigraphList(const std::string& str);
        // Assumes digraphs string has been generated properly
        std::string getDigraph(int i) const;
        std::string toString() const { return digraphs; }
        inline int size() const { return digraphs.size() / 2; }

      private:
        void InsertXBetweenConsecutiveDuplicates( std::string& str );
        std::string digraphs;
    };

    std::string ToUpperCopyAndReplaceJSkippingWhitespace(const std::string& str);
    std::string EncodeMessage(const std::string& in, const EncryptionTable& table);

    void PlayFair(std::istream& input, std::ostream& output);
}

#endif