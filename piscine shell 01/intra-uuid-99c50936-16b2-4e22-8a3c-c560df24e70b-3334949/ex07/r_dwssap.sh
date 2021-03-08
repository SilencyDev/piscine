cat /etc/passwd | sed "/^[\s]*#/d" | awk "NR%2 == 0" | cut -d: -f1 | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | tr "
" "," | sed "s/,/, /g" | sed "s/, $/./g" | tr -d "
"
