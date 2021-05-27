.PHONY: install	
install:	
	mkdir quarantine || true
	mkdir data || true
	mkdir data/scanResults || true
	mkdir data/virusHashDatabase || true
	mkdir data/passiveScanList || true
	sudo touch data/scanResults/ActiveScanResults.txt
	sudo touch data/scanResults/PassiveScanResults.txt
	sudo touch data/passiveScanList/PassiveScanList.txt
	sudo chown root:root quarantine
	sudo chmod 711 quarantine
	sudo chown root:root data/virusHashDatabase/VirusHashes.txt
	sudo chown root:root data/passiveScanList/PassiveScanList.txt
	sudo chmod 644 data/virusHashDatabase/VirusHashes.txt
	sudo chmod 644 data/passiveScanList/PassiveScanList.txt
	sudo chown root:root data/virusHashDatabase
	sudo chmod 711 data/virusHashDatabase
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
	sudo chown root:root antivirusBSO
	sudo chmod 744 antivirusBSO	
	

.PHONY: add_path	
add_path:	
	pwd >> cd && temp.txt
	
