# Image Filter Project: BMP Image Effects

## Usage

Follow these steps to compile and use the program:

1. **Compile the Code**: Open your terminal and navigate to the project directory. Then, run the `make` command to compile the code.

```bash
make
```

2. **Apply Image Filters**: After successfully compiling the code, you can use the following command structure to apply different filters to your BMP image:

```bash
./main <filter_option> <input_file.bmp> <output_file.bmp>
```

Replace `<filter_option>` with one of the following options:

- `-b` or `-blackwhite` for Black and White filter
- `-s` or `-sepia` for Sepia filter
- `-b` or `-blur` for Blur filter
- `-m` or `-mirror` for Mirror effect

Replace `<input_file.bmp>` with the path to your input BMP image file and `<output_file.bmp>` with the desired name of the output BMP image file.

**Example**: To apply the sepia filter, run the following command:

```bash
./main -s input-file.bmp output-file.bmp
```

## Prerequisites

- This project assumes that you have basic knowledge of C programming.
- Ensure you have a C compiler installed on your system (e.g., GCC).

## Implementation Details

The program reads the input BMP image, applies the selected filter, and saves the modified image to the specified output file.

## Acknowledgments

This project is inspired by the need to apply various image effects to BMP images using C programming. It demonstrates basic file I/O and image processing techniques.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute it as needed.

---

*Note: Remember to replace `input-file.bmp` and `output-file.bmp` with actual file paths when using the program.*
