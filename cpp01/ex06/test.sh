#!/bin/bash
make > /dev/null
echo "<debug option>"
./harlFilter debug
echo "---------------------------------------------------------"
echo "<info option>"
./harlFilter info
echo "---------------------------------------------------------"
echo "<warning option>"
./harlFilter warning
echo "---------------------------------------------------------"
echo "<error option>"
./harlFilter error
echo "---------------------------------------------------------"
echo "<invalid option>"
./harlFilter "I am not sure how tired I am today..."
make fclean > /dev/null