#include "../include/HashCalculator.h"
/*
std::string GetFileHash(std::string filename){
	std::string cmd = "sha256sum " + filename;
	std::string data;
	std::FILE * stream;
	const int max_buffer= 256;
	char buffer[max_buffer];
	cmd.append(" 2>&1");
	stream = popen(cmd.c_str(), "r");
	if(stream){
		while(!feof(stream)){
			if(fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
		}
		pclose(stream);
	}
	return data.substr(0,64);
	}
*/
std::string GetFileHash(std::string filename){
	std::ifstream fp(filename, std::ios::in | std::ios::binary);
	if(not fp.good()){
		std::ostringstream os;
	os<< "Cannot open \"" << filename << "\": " << std::strerror(errno) <<".";
	throw std::runtime_error(os.str());
	}
	
	constexpr const std::size_t buffer_size { 1<<12};
	char buffer[buffer_size];
	unsigned char hash[SHA256_DIGEST_LENGTH]= {0};

	SHA256_CTX ctx;

	SHA256_Init(&ctx);

	while(fp.good()){
		fp.read(buffer,buffer_size);
		SHA256_Update(&ctx, buffer, fp.gcount());

	}
	SHA256_Final(hash, &ctx);
	fp.close();
	std::ostringstream os;
	os<< std::hex << std::setfill('0');
	for (int i = 0 ; i< SHA256_DIGEST_LENGTH; ++i){
		os<<std::setw(2) <<static_cast<unsigned int>(hash[i]);

	}
	return os.str();
}
