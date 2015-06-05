#!/usr/bin/env bash

./do-release.sh
scp *.zip static.nettigo.pl:NTG-STATIC/
