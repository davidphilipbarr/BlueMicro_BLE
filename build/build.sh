bash ./linux/nrf52xxx.sh $1:default:all &&

uf2conv.py ../output/$1/$1-pca10056-nicenano-default-right.hex -c -f 0xADA52840 -o $1-right.uf2 &&

uf2conv.py ../output/$1/$1-pca10056-nicenano-default-left.hex -c -f 0xADA52840 -o $1-left.uf2 
