#!/usr/bin/env sh
#
# It will get a text and try to turn it into a coloured one with the repeated lines being highlighted.

#
# João F. © BeyondMagic 2022 <koetemagie@gmail.com>

# 1. All arguments parsed will be seen as the text.
{
  text="$@"
  no_colour="\\\033[0m"
}

{

  tmp="$(date +%s).lrp"

  trap "rm -rf $tmp" EXIT

  touch "$tmp"
}

# 2. To define each unique color for a certain string.
random () {

  # A.a
  message="$@"

  # B.
  read -r red green blue <<EOF
$(shuf -i 0-255 -n 3 | tr '\n' ' ')
EOF

  # A. Set a new RGB 'shell-code' color.
  new_color="\\\033[38;2;${red};${green};${blue}m"

  # C. Replaces it in all of the file.
  text="$(echo "$text" | \
    sed \
    "s=${message}=${new_color}${message}${no_colour}=gm")"

  echo "$text" > "$tmp"

}

# 3. To iterate throughout the unique strings
echo "$text" | awk 'NF' | uniq -u | while read line; do

  random "$line"

done

# 4. 
cat "$tmp"
