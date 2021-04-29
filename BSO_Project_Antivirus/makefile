.PHONY: install	
install:	
	mkdir quarantine || true
	sudo chown root:root quarantine
	sudo chmod 711 quarantine
	mkdir virusHashDatabase || true
	sudo touch virusHashDatabase/VirusHashes.txt || true
	sudo chown root:root virusHashDatabase/VirusHashes.txt
	sudo chmod 644 virusHashDatabase/VirusHashes.txt
	sudo chown root:root virusHashDatabase
	sudo chmod 711 virusHashDatabase
	cd src && make
	
