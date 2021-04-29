.PHONY: install	
install:	
	mkdir quarantine
	sudo chown root:root quarantine
	sudo chmod 711 quarantine
	mkdir virusHashDatabase
	cd virusHashDatabase
	touch VirusHashes.txt
	sudo chown root:root VirusHashes.txt
	sudo chmod 644 VirusHashes.txt
	cd ..
	sudo chown root:root virusHashDatabase
	sudo chmod 711 virusHashDatabase
	cd src
	sudo make
	
