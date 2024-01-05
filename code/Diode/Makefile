LIBRARIES = adcHandler dacHandler phyphoxBLE
PORT = /dev/ttyUSB0
BOARD = esp32:esp32:nodemcu-32s
INO_FILE = Diode.ino

# Default target is to compile and upload
all: compile upload

# Target for compilation
compile:
	arduino-cli --verbose compile --fqbn $(BOARD) $(foreach lib,$(LIBRARIES),--library $(lib)) $(INO_FILE)

# Target for uploading
upload:
	arduino-cli upload --verbose -p $(PORT) --fqbn $(BOARD)

# Target for monitoring
monitor:
	arduino-cli monitor -p $(PORT)

