#!/bin/bash
git="/usr/bin/git"
usage() {
  echo "<commit_mesg> need"
  exit 1 
}
if [ $# -lt 1 ]
then
  usage
fi
$git add .
$git commit -m $1
$git push origin master
