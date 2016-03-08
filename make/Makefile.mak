#Makefile
SRCDIR := source

OBJDIR := obj

BINDIR := bin

HEXDIR := hex

CC := avr-gcc
FLAGS := -Os -DFF_CPU=16000000UL -mmcu=atmega328p -c

HEXDIR_REL := $(addprefix ../, $(HEXDIR))

BINDIR_REL := $(addprefix ../, $(BINDIR))

SRCDIR_REL := $(addprefix ../, $(SRCDIR))

SRCFILES := $(wildcard $(addsuffix /*.c, $(SRCDIR_REL)))

OBJDIR_REL := $(addprefix ../, $(OBJDIR))

OBJFILES := $(patsubst $(SRCDIR_REL)/%.c,$(OBJDIR_REL)/%.o,$(wildcard $(SRCFILES)))

default:
	@echo -e "\e[0;33mmake mStation\e[0;32m - компиляция станции"
	@echo -e "\e[0;33mmake clean\e[0;32m - чистка объектных файлов"
	@echo -e "\e[0;33mmake delete\e[0;32m - удаление исполняемых файлов" 
	
mStation:$(BINDIR_REL)/mStation $(HEXDIR_REL)/mStation.hex  $(OBJFILES)  
	@echo -e "Компиляция mpi программы успешна\n"
flash: $(BINDIR_REL)/mStation $(HEXDIR_REL)/mStation.hex  $(OBJFILES) 
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyUSB0 -b 115200 -U flash:w:$(HEXDIR_REL)/mStation.hex

$(HEXDIR_REL)/mStation.hex: $(BINDIR_REL)/mStation
	avr-objcopy -O ihex -R .eeprom $(BINDIR_REL)/mStation $(HEXDIR_REL)/mStation.hex

$(BINDIR_REL)/mStation: $(OBJFILES) 
	$(CC) -mmcu=atmega328p $^ -o $@ 

	

$(OBJDIR_REL)/%.o: $(SRCDIR_REL)/%.c
	$(CC) $<  $(FLAGS) $(addprefix -I, $(SRCDIR_REL)) -o $@ -pipe 
	
include  $(wildcard $(OBJDIR_REL)/*.d)
#Все пользователи имеют право читать копируется в каталог
clean:
	@rm -f $(OBJDIR_REL)/*.o $(OBJDIR_REL)/*.d
	@rm -f $(OBJDIR_REL_S)/*.o $(OBJDIR_REL_S)/*.d
	@rm -f $(OBJDIR_REL_D)/*.o $(OBJDIR_REL_D)/*.d
	@rm -f $(BINDIR_REL)/*
	@echo "Очистка завершена!"
delete:
	@echo "Клиент удалён!"
	@rm -f $(BINDIR_REL)
	@echo "Сервер удалён!"
.PHONY: clean delete mStation flash