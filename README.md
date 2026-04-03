# A Simple Compression Tool

This is a compression tool that implements a few popular compression algorithms. Right now it includes:

- Test(copy)
- run-length encoding(RLE) x
- Lempel–Ziv–Markov chain algorithm(LZMA) x

x - planned but not included



## Usage/Examples

inside the command line
```
compression -c|-d <inputFile> <outputFile> <algorithm>
```
examples:
```
compression -d "hello.txt" "output.txt" rle
compression -c "uncompressed.txt" "compressed.txt" test
compression -c "anotherFile.txt" "LZMAOutput" LZMA
```

## Appendix

i dont really know what to put here but i want the README to be longer