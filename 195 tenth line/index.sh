#!/user/bin/bash

filename="file.txt"
count=0

while read -r line; do
  ((count++))
  if [ "$count" = 10 ]; then
    echo "$line"
    break
  fi
done < "$filename"
