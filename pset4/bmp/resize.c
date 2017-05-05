/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    
    //resize 
    int n = atoi (argv[1]);
    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    
    if ( n < 1 || n > 100 )
    {
        printf ("Please select integer betweeb 1 and 100 \n");
        return 1; 
    }
    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bf_new;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_new = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, bi_new;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_new = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //---determine new  width and height
    bi_new.biWidth = bi.biWidth * n;
    bi_new.biHeight = bi.biHeight * n;
    
    // determine old and new padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding =  (4 - (bi_new.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //determine new file size and image size
    bi_new.biSizeImage = ( abs(bi_new.biHeight) * (bi_new.biWidth * sizeof (RGBTRIPLE) + new_padding));
    bf_new.bfSize = bf.bfSize - bi.biSizeImage + bi_new.biSizeImage;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_new, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_new, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++) 
    {
        //holizontal repeat
        for (int j = 0; j < n; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
                // write RGB triple to outfile n times
                for (int l = 0; l < n; l++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr); 
            }
            
            //add new_padding
            for (int m = 0; m < new_padding; m++)
                fputc(0x00, outptr);
                
            //back to scanline for repeat n times
            if (j < n-1 )
                fseek (inptr, -bi.biWidth * sizeof (RGBTRIPLE), SEEK_CUR);
            
        }
        //skip original padding if any
        fseek(inptr, padding, SEEK_CUR);
        
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
