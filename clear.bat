@echo off
setlocal enableextensions
if {%1}=={} goto :HELP
if {%1}=={-h} goto :HELP
if {%1}=={all} goto :CLEARALL
if {%1}=={debug} goto :CLEARDEBUG
if {%1}=={release} goto :CLEARRELEASE
goto :HELP

:HELP
echo Usage: %~n0 target or %~n0 nuke directory-name
echo .
echo Empties the contents of the specified directory,
echo WITHOUT CONFIRMATION, USE WITH CAUTION!
goto :DONE

:CLEARALL
:CLEARDEBUG
pushd build\\debug || goto :DONE
rd /q /s . 2> NUL
popd
pushd install\\debug || goto :DONE
rd /q /s . 2> NUL
popd
if not {%1}=={all} goto :DONE

:CLEARRELEASE
pushd build\\release || goto :DONE
rd /q /s . 2> NUL
popd
pushd install\\release || goto :DONE
rd /q /s . 2> NUL
popd

:DONE