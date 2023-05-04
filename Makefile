PROGRAM_DIR =.samples
CPLUS_INCLUDE_PATH =./drio/include
cpp-run:
	CPLUS_INCLUDE_PATH=./drio/include g++  ./src/main.cpp -o main && ./main

gdb-drrun:
	gdb --args drrun -- .samples/yaiwr.x86-64 # ${HOME}/git-repos/Pavel-Durov/pavel.yaiwr/programs/print.yaiwr

ddrun:
	drrun -root ${HOME}/tools/DynamoRIO-Linux-9.0.1 -- .samples/yaiwr.x86-64

init-dirs:
	[ ! -d ${PROGRAM_DIR} ] && mkdir ${PROGRAM_DIR} || echo "${PROGRAM_DIR} already exist"
 
download-samples: mkdirs
	wget -O ${PROGRAM_DIR}/yaiwr.x86-64 https://github.com/Pavel-Durov/yaiwr/releases/download/0.0.1/ELF.64-bit.LSB.pie.executable.x86-64 

