# 1 "../main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "../main.c" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 2 3






# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 2 3
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 127 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 145 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ssize_t;
# 176 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 212 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 254 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 407 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 2 3
# 52 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);


#pragma printf_check(printf) const
#pragma printf_check(vprintf) const
#pragma printf_check(sprintf) const
#pragma printf_check(snprintf) const
#pragma printf_check(vsprintf) const
#pragma printf_check(vsnprintf) const


int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 1 "../main.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 1 3
# 21 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 21 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 2 3


int atoi (const char *);
long atol (const char *);
long long atoll (const char *);
double atof (const char *);

float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);





long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);
long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);

int rand (void);
void srand (unsigned);
# 52 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 3
          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);
# 65 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 3
void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));





__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);
long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);


typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);
# 104 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 3
size_t __ctype_get_mb_cur_max(void);
# 2 "../main.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 1 3
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 135 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 150 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 166 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 181 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int32_t;





typedef long long int64_t;
# 196 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 217 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 237 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 155 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 155 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 2 3
# 3 "../main.c" 2

# 1 "../structs.h" 1
# 13 "../structs.h"
typedef enum{
    SEC1,
    SEC2,
    SEC3,
    SEC4,
    SEC5,
    SEC6

} SVPWM_SEC;


typedef enum{
    V0_REL,
    V1_REL,
    V2_REL,
    V7_REL,
    OFF_REL
}SVPWM_RELATIVE_VEC;


typedef enum{
    V0_ABS,
    V1_ABS,
    V2_ABS,
    V3_ABS,
    V4_ABS,
    V5_ABS,
    V6_ABS,
    V7_ABS,
    OFF_ABS
}SVPWM_ABS_VEC;


typedef struct {
    uint16_t halfZeroVector;
    uint16_t basicVec1;
    uint16_t basicVec2;
    uint16_t totalPeriod;
    uint16_t currentTime;
    uint8_t magnitude;
} SPVWM_Time;


typedef struct {
    int16_t phase_U;
    int16_t phase_V;
    int16_t phase_W;
    uint16_t magnitude;
    uint16_t angle;
} Vector;

typedef struct {




    void (*setTran1)(uint8_t val);
    void (*setTran2)(uint8_t val);
    void (*setTran3)(uint8_t val);
    void (*setTran4)(uint8_t val);
    void (*setTran5)(uint8_t val);
    void (*setTran6)(uint8_t val);

    int16_t ControlAngle;
    int16_t RefAngle;


    SPVWM_Time Timer;

    SVPWM_RELATIVE_VEC State;
    SVPWM_SEC CurrentSector;
    SVPWM_SEC PrevSector;

    Vector motorInput;
    Vector refVector;

} SVPWM;
# 4 "../main.c" 2

# 1 "../trigTables.h" 1
# 13 "../trigTables.h"
static const double sineTable[360] = {
        0.0, 0.0174524064373, 0.0348994967025, 0.0523359562429, 0.0697564737441, 0.0871557427477, 0.104528463268, 0.121869343405, 0.13917310096, 0.15643446504, 0.173648177667, 0.190808995377, 0.207911690818, 0.224951054344, 0.2419218956, 0.258819045103, 0.275637355817, 0.292371704723, 0.309016994375,
        0.325568154457, 0.342020143326, 0.358367949545, 0.374606593416, 0.390731128489, 0.406736643076, 0.422618261741, 0.438371146789, 0.45399049974, 0.469471562786, 0.484809620246, 0.5, 0.51503807491, 0.529919264233, 0.544639035015, 0.559192903471, 0.573576436351, 0.587785252292, 0.601815023152,
        0.615661475326, 0.62932039105, 0.642787609687, 0.656059028991, 0.669130606359, 0.681998360062, 0.694658370459, 0.707106781187, 0.719339800339, 0.731353701619, 0.743144825477, 0.754709580223, 0.766044443119, 0.777145961457, 0.788010753607, 0.798635510047, 0.809016994375, 0.819152044289, 0.829037572555,
        0.838670567945, 0.848048096156, 0.857167300702, 0.866025403784, 0.874619707139, 0.882947592859, 0.891006524188, 0.898794046299, 0.906307787037, 0.913545457643, 0.920504853452, 0.927183854567, 0.933580426497, 0.939692620786, 0.945518575599, 0.951056516295, 0.956304755963, 0.961261695938, 0.965925826289,
        0.970295726276, 0.974370064785, 0.978147600734, 0.981627183448, 0.984807753012, 0.987688340595, 0.990268068742, 0.992546151641, 0.994521895368, 0.996194698092, 0.99756405026, 0.998629534755, 0.999390827019, 0.999847695156, 1.0, 0.999847695156, 0.999390827019, 0.998629534755, 0.99756405026,
        0.996194698092, 0.994521895368, 0.992546151641, 0.990268068742, 0.987688340595, 0.984807753012, 0.981627183448, 0.978147600734, 0.974370064785, 0.970295726276, 0.965925826289, 0.961261695938, 0.956304755963, 0.951056516295, 0.945518575599, 0.939692620786, 0.933580426497, 0.927183854567, 0.920504853452,
        0.913545457643, 0.906307787037, 0.898794046299, 0.891006524188, 0.882947592859, 0.874619707139, 0.866025403784, 0.857167300702, 0.848048096156, 0.838670567945, 0.829037572555, 0.819152044289, 0.809016994375, 0.798635510047, 0.788010753607, 0.777145961457, 0.766044443119, 0.754709580223, 0.743144825477,
        0.731353701619, 0.719339800339, 0.707106781187, 0.694658370459, 0.681998360062, 0.669130606359, 0.656059028991, 0.642787609687, 0.62932039105, 0.615661475326, 0.601815023152, 0.587785252292, 0.573576436351, 0.559192903471, 0.544639035015, 0.529919264233, 0.51503807491, 0.5, 0.484809620246,
        0.469471562786, 0.45399049974, 0.438371146789, 0.422618261741, 0.406736643076, 0.390731128489, 0.374606593416, 0.358367949545, 0.342020143326, 0.325568154457, 0.309016994375, 0.292371704723, 0.275637355817, 0.258819045103, 0.2419218956, 0.224951054344, 0.207911690818, 0.190808995377, 0.173648177667,
        0.15643446504, 0.13917310096, 0.121869343405, 0.104528463268, 0.0871557427477, 0.0697564737441, 0.0523359562429, 0.0348994967025, 0.0174524064373, 1.22464679915e-16, -0.0174524064373, -0.0348994967025, -0.0523359562429, -0.0697564737441, -0.0871557427477, -0.104528463268, -0.121869343405, -0.13917310096, -0.15643446504,
        -0.173648177667, -0.190808995377, -0.207911690818, -0.224951054344, -0.2419218956, -0.258819045103, -0.275637355817, -0.292371704723, -0.309016994375, -0.325568154457, -0.342020143326, -0.358367949545, -0.374606593416, -0.390731128489, -0.406736643076, -0.422618261741, -0.438371146789, -0.45399049974, -0.469471562786,
        -0.484809620246, -0.5, -0.51503807491, -0.529919264233, -0.544639035015, -0.559192903471, -0.573576436351, -0.587785252292, -0.601815023152, -0.615661475326, -0.62932039105, -0.642787609687, -0.656059028991, -0.669130606359, -0.681998360062, -0.694658370459, -0.707106781187, -0.719339800339, -0.731353701619,
        -0.743144825477, -0.754709580223, -0.766044443119, -0.777145961457, -0.788010753607, -0.798635510047, -0.809016994375, -0.819152044289, -0.829037572555, -0.838670567945, -0.848048096156, -0.857167300702, -0.866025403784, -0.874619707139, -0.882947592859, -0.891006524188, -0.898794046299, -0.906307787037, -0.913545457643,
        -0.920504853452, -0.927183854567, -0.933580426497, -0.939692620786, -0.945518575599, -0.951056516295, -0.956304755963, -0.961261695938, -0.965925826289, -0.970295726276, -0.974370064785, -0.978147600734, -0.981627183448, -0.984807753012, -0.987688340595, -0.990268068742, -0.992546151641, -0.994521895368, -0.996194698092,
        -0.99756405026, -0.998629534755, -0.999390827019, -0.999847695156, -1.0, -0.999847695156, -0.999390827019, -0.998629534755, -0.99756405026, -0.996194698092, -0.994521895368, -0.992546151641, -0.990268068742, -0.987688340595, -0.984807753012, -0.981627183448, -0.978147600734, -0.974370064785, -0.970295726276,
        -0.965925826289, -0.961261695938, -0.956304755963, -0.951056516295, -0.945518575599, -0.939692620786, -0.933580426497, -0.927183854567, -0.920504853452, -0.913545457643, -0.906307787037, -0.898794046299, -0.891006524188, -0.882947592859, -0.874619707139, -0.866025403784, -0.857167300702, -0.848048096156, -0.838670567945,
        -0.829037572555, -0.819152044289, -0.809016994375, -0.798635510047, -0.788010753607, -0.777145961457, -0.766044443119, -0.754709580223, -0.743144825477, -0.731353701619, -0.719339800339, -0.707106781187, -0.694658370459, -0.681998360062, -0.669130606359, -0.656059028991, -0.642787609687, -0.62932039105, -0.615661475326,
        -0.601815023152, -0.587785252292, -0.573576436351, -0.559192903471, -0.544639035015, -0.529919264233, -0.51503807491, -0.5, -0.484809620246, -0.469471562786, -0.45399049974, -0.438371146789, -0.422618261741, -0.406736643076, -0.390731128489, -0.374606593416, -0.358367949545, -0.342020143326, -0.325568154457,
        -0.309016994375, -0.292371704723, -0.275637355817, -0.258819045103, -0.2419218956, -0.224951054344, -0.207911690818, -0.190808995377, -0.173648177667, -0.15643446504, -0.13917310096, -0.121869343405, -0.104528463268, -0.0871557427477, -0.0697564737441, -0.0523359562429, -0.0348994967025, -0.0174524064373
};


static const double cosineTable[360] = {
        1.0, 0.999847695156, 0.999390827019, 0.998629534755, 0.99756405026, 0.996194698092, 0.994521895368, 0.992546151641, 0.990268068742, 0.987688340595, 0.984807753012, 0.981627183448, 0.978147600734, 0.974370064785, 0.970295726276, 0.965925826289, 0.961261695938, 0.956304755963, 0.951056516295, 0.945518575599, 0.939692620786,
        0.933580426497, 0.927183854567, 0.920504853452, 0.913545457643, 0.906307787037, 0.898794046299, 0.891006524188, 0.882947592859, 0.874619707139, 0.866025403784, 0.857167300702, 0.848048096156, 0.838670567945, 0.829037572555, 0.819152044289, 0.809016994375, 0.798635510047, 0.788010753607, 0.777145961457, 0.766044443119,
        0.754709580223, 0.743144825477, 0.731353701619, 0.719339800339, 0.707106781187, 0.694658370459, 0.681998360062, 0.669130606359, 0.656059028991, 0.642787609687, 0.62932039105, 0.615661475326, 0.601815023152, 0.587785252292, 0.573576436351, 0.559192903471, 0.544639035015, 0.529919264233, 0.51503807491, 0.5, 0.484809620246,
        0.469471562786, 0.45399049974, 0.438371146789, 0.422618261741, 0.406736643076, 0.390731128489, 0.374606593416, 0.358367949545, 0.342020143326, 0.325568154457, 0.309016994375, 0.292371704723, 0.275637355817, 0.258819045103, 0.2419218956, 0.224951054344, 0.207911690818, 0.190808995377, 0.173648177667, 0.15643446504, 0.13917310096,
        0.121869343405, 0.104528463268, 0.0871557427477, 0.0697564737441, 0.0523359562429, 0.0348994967025, 0.0174524064373, 6.12323399574e-17, -0.0174524064373, -0.0348994967025, -0.0523359562429, -0.0697564737441, -0.0871557427477, -0.104528463268, -0.121869343405, -0.13917310096, -0.15643446504, -0.173648177667, -0.190808995377,
        -0.207911690818, -0.224951054344, -0.2419218956, -0.258819045103, -0.275637355817, -0.292371704723, -0.309016994375, -0.325568154457, -0.342020143326, -0.358367949545, -0.374606593416, -0.390731128489, -0.406736643076, -0.422618261741, -0.438371146789, -0.45399049974, -0.469471562786, -0.484809620246, -0.5, -0.51503807491,
        -0.529919264233, -0.544639035015, -0.559192903471, -0.573576436351, -0.587785252292, -0.601815023152, -0.615661475326, -0.62932039105, -0.642787609687, -0.656059028991, -0.669130606359, -0.681998360062, -0.694658370459, -0.707106781187, -0.719339800339, -0.731353701619, -0.743144825477, -0.754709580223, -0.766044443119, -0.777145961457,
        -0.788010753607, -0.798635510047, -0.809016994375, -0.819152044289, -0.829037572555, -0.838670567945, -0.848048096156, -0.857167300702, -0.866025403784, -0.874619707139, -0.882947592859, -0.891006524188, -0.898794046299, -0.906307787037, -0.913545457643, -0.920504853452, -0.927183854567, -0.933580426497, -0.939692620786, -0.945518575599,
        -0.951056516295, -0.956304755963, -0.961261695938, -0.965925826289, -0.970295726276, -0.974370064785, -0.978147600734, -0.981627183448, -0.984807753012, -0.987688340595, -0.990268068742, -0.992546151641, -0.994521895368, -0.996194698092, -0.99756405026, -0.998629534755, -0.999390827019, -0.999847695156, -1.0, -0.999847695156,
        -0.999390827019, -0.998629534755, -0.99756405026, -0.996194698092, -0.994521895368, -0.992546151641, -0.990268068742, -0.987688340595, -0.984807753012, -0.981627183448, -0.978147600734, -0.974370064785, -0.970295726276, -0.965925826289, -0.961261695938, -0.956304755963, -0.951056516295, -0.945518575599, -0.939692620786, -0.933580426497,
        -0.927183854567, -0.920504853452, -0.913545457643, -0.906307787037, -0.898794046299, -0.891006524188, -0.882947592859, -0.874619707139, -0.866025403784, -0.857167300702, -0.848048096156, -0.838670567945, -0.829037572555, -0.819152044289, -0.809016994375, -0.798635510047, -0.788010753607, -0.777145961457, -0.766044443119, -0.754709580223,
        -0.743144825477, -0.731353701619, -0.719339800339, -0.707106781187, -0.694658370459, -0.681998360062, -0.669130606359, -0.656059028991, -0.642787609687, -0.62932039105, -0.615661475326, -0.601815023152, -0.587785252292, -0.573576436351, -0.559192903471, -0.544639035015, -0.529919264233, -0.51503807491, -0.5, -0.484809620246, -0.469471562786,
        -0.45399049974, -0.438371146789, -0.422618261741, -0.406736643076, -0.390731128489, -0.374606593416, -0.358367949545, -0.342020143326, -0.325568154457, -0.309016994375, -0.292371704723, -0.275637355817, -0.258819045103, -0.2419218956, -0.224951054344, -0.207911690818, -0.190808995377, -0.173648177667, -0.15643446504, -0.13917310096,
        -0.121869343405, -0.104528463268, -0.0871557427477, -0.0697564737441, -0.0523359562429, -0.0348994967025, -0.0174524064373, -1.83697019872e-16, 0.0174524064373, 0.0348994967025, 0.0523359562429, 0.0697564737441, 0.0871557427477, 0.104528463268, 0.121869343405, 0.13917310096, 0.15643446504, 0.173648177667, 0.190808995377, 0.207911690818,
        0.224951054344, 0.2419218956, 0.258819045103, 0.275637355817, 0.292371704723, 0.309016994375, 0.325568154457, 0.342020143326, 0.358367949545, 0.374606593416, 0.390731128489, 0.406736643076, 0.422618261741, 0.438371146789, 0.45399049974, 0.469471562786, 0.484809620246, 0.5, 0.51503807491, 0.529919264233, 0.544639035015, 0.559192903471,
        0.573576436351, 0.587785252292, 0.601815023152, 0.615661475326, 0.62932039105, 0.642787609687, 0.656059028991, 0.669130606359, 0.681998360062, 0.694658370459, 0.707106781187, 0.719339800339, 0.731353701619, 0.743144825477, 0.754709580223, 0.766044443119, 0.777145961457, 0.788010753607, 0.798635510047, 0.809016994375, 0.819152044289,
        0.829037572555, 0.838670567945, 0.848048096156, 0.857167300702, 0.866025403784, 0.874619707139, 0.882947592859, 0.891006524188, 0.898794046299, 0.906307787037, 0.913545457643, 0.920504853452, 0.927183854567, 0.933580426497, 0.939692620786, 0.945518575599, 0.951056516295, 0.956304755963, 0.961261695938, 0.965925826289, 0.970295726276,
        0.974370064785, 0.978147600734, 0.981627183448, 0.984807753012, 0.987688340595, 0.990268068742, 0.992546151641, 0.994521895368, 0.996194698092, 0.99756405026, 0.998629534755, 0.999390827019, 0.999847695156
};
# 5 "../main.c" 2

# 1 "../functions.h" 1







# 1 "../structs.h" 1
# 8 "../functions.h" 2

# 1 "../trigTables.h" 1
# 9 "../functions.h" 2

# 1 "../transistors.h" 1







# 1 "../structs.h" 1
# 8 "../transistors.h" 2

# 1 "../trigTables.h" 1
# 9 "../transistors.h" 2
# 25 "../transistors.h"
void SVPWM_WriteV0(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(0);
    (*pm).setTran3(0);

    (*pm).setTran4(1);
    (*pm).setTran5(1);
    (*pm).setTran6(1);
}


void SVPWM_WriteV1(SVPWM *pm) {
    (*pm).setTran1(1);
    (*pm).setTran2(0);
    (*pm).setTran3(0);

    (*pm).setTran4(0);
    (*pm).setTran5(1);
    (*pm).setTran6(1);
}


void SVPWM_WriteV2(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(1);
    (*pm).setTran3(0);

    (*pm).setTran4(1);
    (*pm).setTran5(0);
    (*pm).setTran6(1);
}


void SVPWM_WriteV3(SVPWM *pm) {
    (*pm).setTran1(1);
    (*pm).setTran2(1);
    (*pm).setTran3(0);

    (*pm).setTran4(0);
    (*pm).setTran5(0);
    (*pm).setTran6(1);
}


void SVPWM_WriteV4(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(0);
    (*pm).setTran3(1);

    (*pm).setTran4(1);
    (*pm).setTran5(1);
    (*pm).setTran6(0);
}


void SVPWM_WriteV5(SVPWM *pm) {
    (*pm).setTran1(1);
    (*pm).setTran2(0);
    (*pm).setTran3(1);

    (*pm).setTran4(0);
    (*pm).setTran5(1);
    (*pm).setTran6(0);
}


void SVPWM_WriteV6(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(1);
    (*pm).setTran3(1);

    (*pm).setTran4(1);
    (*pm).setTran5(0);
    (*pm).setTran6(0);
}


void SVPWM_WriteV7(SVPWM *pm) {
    (*pm).setTran1(1);
    (*pm).setTran2(1);
    (*pm).setTran3(1);

    (*pm).setTran4(0);
    (*pm).setTran5(0);
    (*pm).setTran6(0);
}


void SVPWM_WriteOFF(SVPWM *pm) {
    (*pm).setTran1(0);
    (*pm).setTran2(0);
    (*pm).setTran3(0);

    (*pm).setTran4(0);
    (*pm).setTran5(0);
    (*pm).setTran6(0);
}
# 10 "../functions.h" 2
# 26 "../functions.h"
SVPWM_SEC SVPWM_GetControlAngleSEC(SVPWM *pm) {



    return ((*pm).ControlAngle / (0x3FFF*60/360)) % 6;
}


void SVPWM_SetCurrentSEC(SVPWM *pm) {
    (*pm).CurrentSector = SVPWM_GetControlAngleSEC(pm);
}


void SVPWM_UpdateCurrentTimer(SVPWM *pm) {
    switch((*pm).State){
        case V0_ABS:
            (*pm).Timer.currentTime = (*pm).Timer.halfZeroVector;
            break;
        case V1_ABS:
            (*pm).Timer.currentTime = (*pm).Timer.basicVec1;
            break;
        case V2_ABS:
            (*pm).Timer.currentTime = (*pm).Timer.basicVec2;
            break;
        case V7_REL:
            (*pm).Timer.currentTime = (*pm).Timer.halfZeroVector;
            break;
        default:
            return;
    }
}


SVPWM_ABS_VEC SVPWM_GetAbsoluteVoltageVector(SVPWM *pm) {

    if((*pm).State == V0_REL)
        return V0_ABS;
    if((*pm).State == V7_REL)
        return V7_ABS;

    switch((*pm).CurrentSector) {
        case SEC1:
            if((*pm).State == V1_REL)
                return V1_ABS;
            if((*pm).State == V2_REL)
                return V3_ABS;
            break;
        case SEC2:
            if((*pm).State == V1_REL)
                return V3_ABS;
            if((*pm).State == V2_REL)
                return V2_ABS;
            break;
        case SEC3:
            if((*pm).State == V1_REL)
                return V2_ABS;
            if((*pm).State == V2_REL)
                return V6_ABS;
            break;
        case SEC4:
            if((*pm).State == V1_REL)
                return V6_ABS;
            if((*pm).State == V2_REL)
                return V4_ABS;
            break;
        case SEC5:
            if((*pm).State == V1_REL)
                return V4_ABS;
            if((*pm).State == V2_REL)
                return V5_ABS;
            break;
        case SEC6:
            if((*pm).State == V1_REL)
                return V5_ABS;
            if((*pm).State == V2_REL)
                return V1_ABS;
            break;
        default:
            return OFF_ABS;
    }
}


void SVPWM_SetNextRelativeState(SVPWM *pm) {
    switch((*pm).State) {
        case V0_REL:
            (*pm).State = V1_REL;
            break;
        case V1_REL:
            (*pm).State = V2_REL;
            break;
        case V2_REL:
            (*pm).State = V7_REL;
            break;
        case V7_REL:
            (*pm).State = V0_REL;
            break;
        default:
            return;
    }
}


void SVPWM_SetControlAngle(SVPWM *pm, uint16_t inputAngle) {
    (*pm).ControlAngle = inputAngle;
    (*pm).RefAngle = inputAngle % (0x3FFF*60/360);
}


void SVPWM_SetVectorTimes(SVPWM *pm) {
    uint8_t sector;
    uint16_t sectorIndex, angleIndex;
    sector = (*pm).CurrentSector + 1;
    printf("Sector + 1 %d\r\n", sector);
    sectorIndex = sector * 60 - 1;
    printf("Sector index %d\r\n", sectorIndex);
    angleIndex = (*pm).RefAngle * 60 / 0x3FFF;
    printf("Angle Index %d\r\n", angleIndex);

    (*pm).Timer.basicVec1 = (1.73205080757 * (*pm).Timer.totalPeriod * (sineTable[sectorIndex] * cosineTable[angleIndex] - sineTable[angleIndex] * cosineTable[sectorIndex]));

    sectorIndex = (sector - 1) * 60;
    (*pm).Timer.basicVec2 = (1.73205080757 * (*pm).Timer.totalPeriod * (- sineTable[sectorIndex] * cosineTable[angleIndex] + sineTable[angleIndex] * cosineTable[sectorIndex]));

    (*pm).Timer.halfZeroVector = ((*pm).Timer.totalPeriod - (*pm).Timer.basicVec1 - (*pm).Timer.basicVec2) >> 1;

}


void SVPWM_WriteABSVector(SVPWM *pm) {
    switch(SVPWM_GetAbsoluteVoltageVector(pm)){
        case V0_ABS:
            SVPWM_WriteV0(pm);
            break;
        case V1_ABS:
            SVPWM_WriteV1(pm);
            break;
        case V2_ABS:
            SVPWM_WriteV2(pm);
            break;
        case V3_ABS:
            SVPWM_WriteV3(pm);
            break;
        case V4_ABS:
            SVPWM_WriteV4(pm);
            break;
        case V5_ABS:
            SVPWM_WriteV5(pm);
            break;
        case V6_ABS:
            SVPWM_WriteV6(pm);
            break;
        case V7_ABS:
            SVPWM_WriteV7(pm);
            break;
        default:

            SVPWM_WriteOFF(pm);
    }
}


void SVPWM_STDISR(SVPWM *pm) {
    SVPWM_SetCurrentSEC(pm);
    SVPWM_SetNextRelativeState(pm);
    SVPWM_WriteABSVector(pm);
    SVPWM_SetVectorTimes(pm);
    SVPWM_UpdateCurrentTimer(pm);
}

uint16_t Test_setTimer(uint16_t time) {
    printf("Time: %d\n\r", time);
}


uint8_t TEST_V0(uint8_t input) {
    if(input == 0)
        printf("T0: OFF\n\r");
    if(input == 1)
        printf("T0: ON\n\r");
}

uint8_t TEST_V1(uint8_t input) {
    if(input == 0)
        printf("T1: OFF\n\r");
    if(input == 1)
        printf("T1: ON\n\r");
}

uint8_t TEST_V2(uint8_t input) {
    if(input == 0)
        printf("T2: OFF\n\r");
    if(input == 1)
        printf("T2: ON\n\r");
}

uint8_t TEST_V3(uint8_t input) {
    if(input == 0)
        printf("T3: OFF\n\r");
    if(input == 1)
        printf("T3: ON\n\r");
}

uint8_t TEST_V4(uint8_t input) {
    if(input == 0)
        printf("T4: OFF\n\r");
    if(input == 1)
        printf("T4: ON\n\r");
}

uint8_t TEST_V5(uint8_t input) {
    if(input == 0)
        printf("T5: OFF\n\r");
    if(input == 1)
        printf("T5: ON\n\r");
}

uint8_t TEST_V6(uint8_t input) {
    if(input == 0)
        printf("T6: OFF\n\r");
    if(input == 1)
        printf("T6: ON\n\r");
}
# 6 "../main.c" 2

# 1 "../transistors.h" 1







# 1 "../structs.h" 1
# 8 "../transistors.h" 2

# 1 "../trigTables.h" 1
# 9 "../transistors.h" 2
# 7 "../main.c" 2
# 19 "../main.c"
SVPWM pwmBoi;

void fakeISR() {
    SVPWM_STDISR(&pwmBoi);
    Test_setTimer(0xFFFF - pwmBoi.Timer.currentTime);
}

int main() {

    pwmBoi.setTran1 = TEST_V1;
    pwmBoi.setTran2 = TEST_V2;
    pwmBoi.setTran3 = TEST_V3;
    pwmBoi.setTran4 = TEST_V4;
    pwmBoi.setTran5 = TEST_V5;
    pwmBoi.setTran6 = TEST_V6;


    SVPWM_SetControlAngle(&pwmBoi, (0x3FFF*75/360));


    SVPWM_SetCurrentSEC(&pwmBoi);
    printf("Sector: %u\n\r", pwmBoi.CurrentSector);



    pwmBoi.Timer.totalPeriod = 30000;
    pwmBoi.Timer.magnitude = 0x7F;
    SVPWM_SetVectorTimes(&pwmBoi);

    pwmBoi.refVector.magnitude = 1000;
# 74 "../main.c"
    uint16_t TEST_Angles [19] = {12, 45, 59, 60, 105, 119, 120, 155, 179, 180, 203, 239, 240, 258, 299, 300, 315, 359, 360};

    for(int i = 0; i < 19; i ++){
        printf("--------------------------------------------------\n\r");
        printf("Angle: %d\n\r", TEST_Angles[i]);
        printf("Angle: %d\n\r", pwmBoi.RefAngle * 60 / 0x3FFF);
        SVPWM_SetControlAngle(&pwmBoi, (0x3FFF*TEST_Angles[i]/360));
        printf("Control Angle: %d\n\r", pwmBoi.ControlAngle);
        printf("Ref Angle: %d\n\r", pwmBoi.RefAngle);
        fakeISR();
        printf("ABS Voltage: %d\n\r", SVPWM_GetAbsoluteVoltageVector(&pwmBoi));
        printf("Sector: %d\n\r", (pwmBoi.CurrentSector));
        printf("Current State: %d\n\r", pwmBoi.State);
        printf("Total Period: %u\n\r", pwmBoi.Timer.totalPeriod);
        printf("Half Vec Time: %u\n\r", pwmBoi.Timer.halfZeroVector);
        printf("Vec 1 Time: %u\n\r", pwmBoi.Timer.basicVec1);
        printf("Vec 2 Time: %u\n\r", pwmBoi.Timer.basicVec2);

    }

    return 0;
}
