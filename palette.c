#include "palette.h"

#include <stdio.h>
#include <math.h>

color_t palette[255]={
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{0,0,0,0},
{35,35,23,0},
{51,51,35,0},
{67,67,47,0},
{83,83,63,0},
{99,99,75,0},
{115,115,91,0},
{131,131,111,0},
{151,151,131,0},
{175,175,159,0},
{195,195,183,0},
{219,219,211,0},
{243,243,239,0},
{0,47,51,0},
{0,59,63,0},
{11,75,79,0},
{19,91,91,0},
{31,107,107,0},
{47,123,119,0},
{59,139,135,0},
{79,155,151,0},
{95,175,167,0},
{115,191,187,0},
{139,207,203,0},
{163,227,223,0},
{7,43,67,0},
{11,59,87,0},
{23,75,111,0},
{31,87,127,0},
{39,99,143,0},
{51,115,159,0},
{67,131,179,0},
{87,151,191,0},
{111,175,203,0},
{135,199,219,0},
{163,219,231,0},
{195,239,247,0},
{0,27,71,0},
{0,43,95,0},
{0,63,119,0},
{7,83,143,0},
{7,111,167,0},
{15,139,191,0},
{19,167,215,0},
{27,203,243,0},
{47,231,255,0},
{95,243,255,0},
{143,251,255,0},
{195,255,255,0},
{0,0,35,0},
{0,0,79,0},
{7,7,95,0},
{15,15,111,0},
{27,27,127,0},
{39,39,143,0},
{59,59,163,0},
{79,79,179,0},
{103,103,199,0},
{127,127,215,0},
{159,159,235,0},
{191,191,255,0},
{19,51,27,0},
{23,63,35,0},
{31,79,47,0},
{39,95,59,0},
{43,111,71,0},
{51,127,87,0},
{59,143,99,0},
{67,155,115,0},
{75,171,131,0},
{83,187,147,0},
{95,203,163,0},
{103,219,183,0},
{27,55,31,0},
{35,71,47,0},
{43,83,59,0},
{55,99,75,0},
{67,111,91,0},
{79,135,111,0},
{95,159,135,0},
{111,183,159,0},
{127,207,183,0},
{147,219,195,0},
{167,231,207,0},
{191,247,223,0},
{0,63,15,0},
{0,83,19,0},
{0,103,23,0},
{0,123,31,0},
{7,143,39,0},
{23,159,55,0},
{39,175,71,0},
{63,191,91,0},
{87,207,111,0},
{115,223,139,0},
{143,239,163,0},
{179,255,195,0},
{19,43,79,0},
{27,55,99,0},
{43,71,119,0},
{59,87,139,0},
{67,99,167,0},
{83,115,187,0},
{99,131,207,0},
{115,151,215,0},
{131,171,227,0},
{151,191,239,0},
{171,207,247,0},
{195,227,255,0},
{55,19,15,0},
{87,43,39,0},
{103,55,51,0},
{119,67,63,0},
{139,83,83,0},
{155,99,99,0},
{175,119,119,0},
{191,139,139,0},
{207,159,159,0},
{223,183,183,0},
{239,211,211,0},
{255,239,239,0},
{111,27,0,0},
{151,39,0,0},
{167,51,7,0},
{187,67,15,0},
{203,83,27,0},
{223,103,43,0},
{227,135,67,0},
{231,163,91,0},
{239,187,119,0},
{243,211,143,0},
{251,231,175,0},
{255,247,215,0},
{15,43,11,0},
{23,55,15,0},
{31,71,23,0},
{43,83,35,0},
{59,99,47,0},
{75,115,59,0},
{95,135,79,0},
{119,155,99,0},
{139,175,123,0},
{167,199,147,0},
{195,219,175,0},
{223,243,207,0},
{95,0,63,0},
{115,7,75,0},
{127,15,83,0},
{143,31,95,0},
{155,43,107,0},
{171,63,123,0},
{187,83,135,0},
{199,103,155,0},
{215,127,171,0},
{231,155,191,0},
{243,195,215,0},
{255,235,243,0},
{0,0,63,0},
{0,0,87,0},
{0,0,115,0},
{0,0,143,0},
{0,0,171,0},
{0,0,199,0},
{0,7,227,0},
{0,7,255,0},
{67,79,255,0},
{115,123,255,0},
{163,171,255,0},
{215,219,255,0},
{0,39,79,0},
{0,51,111,0},
{0,63,147,0},
{0,71,183,0},
{0,79,219,0},
{0,83,255,0},
{23,111,255,0},
{51,139,255,0},
{79,163,255,0},
{107,183,255,0},
{135,203,255,0},
{163,219,255,0},
{47,51,0,0},
{55,63,0,0},
{67,75,0,0},
{79,87,0,0},
{99,107,7,0},
{119,127,23,0},
{143,147,43,0},
{163,167,71,0},
{187,187,99,0},
{207,207,131,0},
{231,231,171,0},
{255,255,207,0},
{27,0,63,0},
{51,0,103,0},
{63,11,123,0},
{79,23,143,0},
{95,31,163,0},
{111,39,183,0},
{143,59,219,0},
{171,91,239,0},
{187,119,243,0},
{203,151,247,0},
{223,183,251,0},
{239,215,255,0},
{0,19,39,0},
{7,31,55,0},
{15,47,71,0},
{31,63,91,0},
{51,83,107,0},
{75,103,123,0},
{107,127,143,0},
{127,147,163,0},
{147,171,187,0},
{171,195,207,0},
{195,219,231,0},
{223,243,255,0},
{75,75,55,0},
{0,183,255,0},
{0,219,255,0},
{0,255,255,0},
{135,143,39,0},
{99,107,7,0},
{99,107,7,0},
{99,107,7,0},
{123,131,27,0},
{227,227,155,0},
{151,155,55,0},
{151,155,55,0},
{151,155,55,0},
{203,203,115,0},
{91,91,67,0},
{107,107,83,0},
{123,123,99,0},
{8,67,8,0},
{16,85,16,0},
{24,103,24,0},
{32,121,32,0},
{40,139,40,0},
{48,157,48,0},
{56,175,56,0},
{64,193,64,0},
{72,211,72,0},
{80,219,80,0},
{88,237,88,0},
{92,255,92,0}
};


uint8_t remap[36][12]={
{10,10,10,10,10,11,12,13,14,15,16,17},
{10,11,12,13,14,15,16,17,18,19,20,21},
{13,14,15,16,17,18,19,20,21,21,21,21},
{118,118,118,119,119,120,121,122,122,123,124,124},
{118,119,120,121,122,123,124,125,126,127,128,129},
{154,155,156,157,158,159,160,161,162,163,164,165},
{130,130,130,131,131,132,133,134,134,135,136,136},
{130,131,132,133,134,135,136,137,138,139,140,141},
{133,134,135,136,137,138,139,140,140,141,141,141},
{190,191,192,193,194,195,196,197,198,199,200,201},
{191,193,195,196,197,198,199,200,200,201,201,201},
{94,94,94,95,95,96,97,98,98,99,100,100},
{142,143,144,145,146,147,148,149,150,151,152,153},
{70,71,72,73,74,75,76,77,78,79,80,81},
{94,95,96,97,98,99,100,101,102,103,104,105},
{82,83,84,85,86,87,88,89,90,91,92,93},
{22,23,24,25,26,27,28,29,30,31,32,33},
{48,49,50,51,52,53,54,55,56,56,57,57},
{46,47,48,49,50,51,52,53,54,55,56,57},
{46,46,46,47,47,48,49,50,51,52,53,53},
{178,179,180,181,182,183,184,185,186,187,188,189},
{178,178,178,179,179,180,181,182,182,183,184,184},
{34,35,36,37,38,39,40,41,42,43,44,45},
{34,34,34,34,35,36,37,38,39,40,41,42},
{214,214,215,216,217,218,219,220,221,222,223,224},
{106,107,108,109,110,111,112,113,114,115,116,117},
{58,59,60,61,62,63,64,65,66,67,68,69},
{166,166,166,167,167,168,169,170,170,171,172,172},
{166,167,168,169,170,171,172,173,174,175,176,177},
{202,202,202,203,203,204,205,206,206,207,208,208},
{202,203,204,205,206,207,208,209,210,211,212,213},
{15,16,17,18,19,20,20,20,21,21,21,21},
//Special peep colors
{108,109,110,111,112,113,114,115,116,116,117,117},//Skin
{105,105,106,106,106,107,107,107,108,108,109,109},//Legs/Hair
{243,244,245,246,246,247,247,248,248,248,249,250},//Remap1 -- These are darker than the normal remap colors
{202,203,204,205,205,206,206,207,207,207,208,209},//Remap2  /
};


uint8_t palette_remap_section_index(uint8_t color,uint8_t section_index)
{
    if(color==TRANSPARENT)return 0;
    if(color==COLOR_REMAP_1)return 243+section_index;
    if(color==COLOR_REMAP_2)return 202+section_index;
    if(color==COLOR_REMAP_3)return 46+section_index;
return remap[color][section_index];
}


color_t palette_color_from_index(uint8_t index)
{
return palette[index];
}

uint8_t palette_index_from_color(color_t color)
{
int i;
    for(i=0;i<256;i++)
    {
        if(color.red==palette[i].red&&color.green==palette[i].green&&color.blue==palette[i].blue)
        {
        return i;
        }
    }
return 0;
}

/*Each color has 12 shades from dark to light (section_index above). This calculates the
linear regression line between the luminance and the section index - that is, the best
approximation for the luminance given only the section index. This function isn't actually
called since the result will always be the same - instead, the results are hardcoded where they're needed*/

void palette_calculate_regression()
{
int i,j;

float xy_mean=0.0;
float xx_mean=0.0;
float yy_mean=0.0;
float x_mean=0.0;
float y_mean=0.0;
float n=0.0;
float x;
    for(i=1;i<30;i+=3)
    {
    x=0;
        for(j=0;j<12;j++)
        {
        int index=palette_remap_section_index(i,j);
        float r=(float)palette[index].red/255.0;
        float g=(float)palette[index].green/255.0;
        float b=(float)palette[index].blue/255.0;
        //Calculate relative luminance from rgb components
        float y=0.2126*r+0.7152*g+0.0722*b;
        xy_mean+=x*y;
        xx_mean+=x*x;
        yy_mean+=y*y;
        x_mean+=x;
        y_mean+=y;
        n+=1.0;
        x+=1.0;
        }
    }
xy_mean/=n;
xx_mean/=n;
yy_mean/=n;
x_mean/=n;
y_mean/=n;

float x_stddev=sqrt((xx_mean-x_mean*x_mean));
float y_stddev=sqrt((yy_mean-y_mean*y_mean));
float correlation=(xy_mean-x_mean*y_mean)/(x_stddev*y_stddev);
float slope=correlation*(y_stddev/x_stddev);
float intercept=y_mean-slope*x_mean;

printf("intercept %f slope %f\n",intercept,slope);
}
