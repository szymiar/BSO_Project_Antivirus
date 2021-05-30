.PHONY: install	
install:	
	sudo mkdir /usr/local/share/BSO_Project_Antivirus
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/quarantine
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/scanResults
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/virusHashDatabase
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/passiveScanList
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/BackupService
	sudo mkdir /usr/local/share/BSO_Project_Antivirus/data/BackupService/BackupFolder
	sudo cp -R test /usr/local/share/BSO_Project_Antivirus/test
	sudo cp -R include /usr/local/include/BSO_Project_Antivirus
	sudo cp -R src /usr/local/src/BSO_Project_Antivirus
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
	sudo rm -r /usr/local/share/BSO_Project_Antivirus
	sudo rm -r src/obj
	sudo rm -r /usr/local/include/BSO_Project_Antivirus
	sudo rm -r /usr/local/src/BSO_Project_Antivirus



.PHONY: update	
update:	
	cd src && sudo make	
	sudo chown root:root /usr/local/bin/antivirusBSO
	sudo chmod 744 /usr/local/bin/antivirusBSO	
	
