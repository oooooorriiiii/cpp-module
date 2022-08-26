./ex02.out | cut -f 2 -d ' ' > output
cat 19920104_091532.log | cut -f 2 -d ' ' > expected
diff output expected