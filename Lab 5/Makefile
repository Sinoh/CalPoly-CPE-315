C = g++
CFLAGS = -g -Wall -O3
SOURCE = matmul.cpp matmul_driver.cpp 
SOURCE_ColMaj = matmul_ColMaj.cpp matmul_driver.cpp 
SOURCE_Tile16 = matmul_Tile16.cpp matmul_driver.cpp 
SOURCE_Tile32 = matmul_Tile32.cpp matmul_driver.cpp 
OUT = mm
OUT_ColMaj = mm_ColMaj
OUT_Tile16 = mm_Tile16
OUT_Tile32 = mm_Tile32

Matmul:
	$(C) $(CFLAGS) -c $(SOURCE)
	$(C) $(CFLAGS) -o $(OUT) *.o
	make clean

ColMaj:
	$(C) $(CFLAGS) -c $(SOURCE_ColMaj)
	$(C) $(CFLAGS) -o $(OUT_ColMaj) *.o
	make clean

Tile16:
	$(C) $(CFLAGS) -c $(SOURCE_Tile16)
	$(C) $(CFLAGS) -o $(OUT_Tile16) *.o
	make clean

Tile32:
	$(C) $(CFLAGS) -c $(SOURCE_Tile32)
	$(C) $(CFLAGS) -o $(OUT_Tile32) *.o
	make clean

clean:
	rm -f *.o
