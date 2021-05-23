.PHONY: install	
install:	
	mkdir quarantine || true
	sudo chown root:root quarantine
	sudo chmod 711 quarantine
	mkdir virusHashDatabase || true
	mkdir passiveScanList || true
	sudo touch passiveScanList/PassiveScanList.txt || true
	sudo touch virusHashDatabase/VirusHashes.txt || true
	sudo chown root:root virusHashDatabase/VirusHashes.txt
	sudo chown root:root passiveScanList/PassiveScanList.txt
	sudo chmod 644 virusHashDatabase/VirusHashes.txt
	sudo chmod 644 passiveScanList/PassiveScanList.txt
	sudo chown root:root virusHashDatabase
	sudo chmod 711 virusHashDatabase
	mkdir src/obj || true
	cd src && make
	sudo chown root:root antivirusBSO
	sudo chmod 744 antivirusBSO
	
.PHONY: uninstall	
uninstall:	
	cd src && sudo make clean	
	



.PHONY: update	
update:	
	cd src && sudo make	

