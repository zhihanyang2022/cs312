#!/bin/bash

# `pwd` in backquotes represents the output of the command pwd

# if true it then execute rm -fR build/*
# if the command had said rm -fR build without the /* it would have removed the build folder and its contents
# the /* removes contents of build but does not remove build
if [ -d "`pwd`/build" ]
# -d is a test whether the build folder exists
# if you were already in the build folder the above command would return false
# unless you had a build folder inside your build folder
then
# -f = force, R = recursive to delete everything inside build.
  rm -fR build/*
elif [ -d ../build ]
# this -d checks for a build folder in the parent folder of the working directory
# if you're in the the source folder then you'll have a build folder
then
  rm -fR ../build/*
elif [ -d "`pwd`/build-debug" ]
# later classes will use build for release version and build-debug for debug version
then
  rm -fR build-debug/*
elif [ -d ../build-debug ]
then
  rm -fR ../build-debug/*
else
  echo  "no build or build-debug folder found"
fi
  exit 0