#!/bin/bash


set -e; set -u
COMMON_SUBDOMAINS="www mail mx a.mx smtp pop imap blog en ftp ssh login"
EXTENDED=""

while :; do case "$1" in
  --) shift; break ;;
  -x) EXTENDED=y; shift ;;
  -s) NS="$2"; shift 2 ;;
  *) break ;;
esac; done
DOM="$1"; shift
TYPE="${1:-any}"

test "${NS:-}" || NS=$(dig +short  SOA "$DOM" | awk '{print $1}')
test "$NS" && NS="@$NS"

if test "$EXTENDED"; then
  dig +nocmd $NS "$DOM" +noall +answer "$TYPE"
  wild_ips=$(dig +short "$NS" "*.$DOM" "$TYPE" | tr '\n' '|')
  wild_ips="${wild_ips%|}"
  for sub in $COMMON_SUBDOMAINS; do
    dig +nocmd $NS "$sub.$DOM" +noall +answer "$TYPE"
  done | cat  #grep -vE "${wild_ips}"
  dig +nocmd $NS "*.$DOM" +noall +answer "$TYPE"
else
  dig +nocmd $NS "$DOM" +noall +answer "$TYPE"
fi
