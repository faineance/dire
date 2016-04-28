# dire

## Building
```shell
mkdir build && cd build
cmake ..
```

## Usage
```shell
echo -ne "\xb8\x2a\x00\x00\x00\xc3" > test.bin
./dire < test.bin
```
