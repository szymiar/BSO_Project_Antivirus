.PHONY: install	
install:	
	mkdir quarantine || true
	mkdir data || true
	mkdir data/scanResults || true
	mkdir data/virusHashDatabase || true
	mkdir data/passiveScanList || true
	mkdir data/BackupService || true
	mkdir data/BackupService/BackupFolder || true
	sudo touch data/BackupService/BackupFolderList.txt
	sudo touch data/scanResults/ActiveScanResults.txt
	sudo touch data/scanResults/PassiveScanResults.txt
	sudo touch data/passiveScanList/PassiveScanList.txt
	sudo touch data/passiveScanList/PassiveScanState.txt
	sudo chown root:root quarantine
	sudo chown root:root data/BackupService/BackupFolder
	sudo chmod 711 quarantine
	sudo chmod 711 data/BackupService/BackupFolder
	sudo chown root:root data/virusHashDatabase/VirusHashes.txt
	sudo chown root:root data/passiveScanList/PassiveScanList.txt
	sudo chown root:root data/passiveScanList/PassiveScanState.txt
	sudo chmod 611 data/passiveScanList/PassiveScanState.txt
	sudo chmod 644 data/virusHashDatabase/VirusHashes.txt
	sudo chmod 644 data/BackupService/BackupFolderList.txt
	sudo chmod 644 data/passiveScanList/PassiveScanList.txt
	sudo chown root:root data/virusHashDatabase
	sudo chmod 711 data/virusHashDatabase
	sudo mkdir /usr/local/share/BSO_Project_Antivirus || true
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/quarantine || true
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data || true
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/scanResults || true
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/virusHashDatabase || true
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/passiveScanList || true
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/BackupService || true
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/BackupService/BackupFolder || true
	sudo cp -R test /usr/local/share/BSO_Project_Antivirus/test || true
	sudo touch /usr/local/share/BSO_Project_Antivirus/data/BackupService/BackupFolderList.txt
	sudo touch /usr/local/share/BSO_Project_Antivirus/data/scanResults/ActiveScanResults.txt
	sudo touch /usr/local/share/BSO_Project_Antivirus/data/scanResults/PassiveScanResults.txt
	sudo touch /usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanList.txt
	sudo touch /usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanState.txt
	sudo cp data/virusHashDatabase/VirusHashes.txt /usr/local/share/BSO_Project_Antivirus/data/virusHashDatabase/VirusHashes.txt
	sudo chown root:root /usr/local/share/BSO_Project_Antivirus/quarantine
	sudo chown root:root /usr/local/share/BSO_Project_Antivirus/data/BackupService/BackupFolder
	sudo chown root:root /usr/local/share/BSO_Project_Antivirus/data/virusHashDatabase
	sudo chown root:root /usr/local/share/BSO_Project_Antivirus/data/virusHashDatabase/VirusHashes.txt
	sudo chown root:root /usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanList.txt
	sudo chown root:root /usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanState.txt
	sudo chown root:root /usr/local/share/BSO_Project_Antivirus/data/BackupService/BackupFolderList.txt
	sudo chmod 711 /usr/local/share/BSO_Project_Antivirus/quarantine
	sudo chmod 711 /usr/local/share/BSO_Project_Antivirus/data/BackupService/BackupFolder
	sudo chmod 711 /usr/local/share/BSO_Project_Antivirus/data/virusHashDatabase
	sudo chmod 611 /usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanState.txt
	sudo chmod 611 /usr/local/share/BSO_Project_Antivirus/data/virusHashDatabase/VirusHashes.txt
	sudo chmod 611 /usr/local/share/BSO_Project_Antivirus/data/BackupService/BackupFolderList.txt
	sudo chmod 611 /usr/local/share/BSO_Project_Antivirus/data/passiveScanList/PassiveScanList.txt
	mkdir src/obj || true
	cd src && make
	sudo chown root:root /usr/local/bin/antivirusBSO
	sudo chmod 744 /usr/local/bin/antivirusBSO
	
.PHONY: uninstall	
uninstall:	
	cd src && sudo make clean	
	



.PHONY: update	
update:	
	cd src && sudo make	
	sudo chown root:root /usr/local/bin/antivirusBSO
	sudo chmod 744 /usr/local/bin/antivirusBSO	
	

.PHONY: add_path	
add_path:	
	pwd >> cd && temp.txt
	
