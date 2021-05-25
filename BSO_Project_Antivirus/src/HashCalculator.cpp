#include "../include/HashCalculator.h"
#include "../include/FileHandler.h"
std::string GetFileHash(std::string filename){
	std::cout<<"\nCheck 5\n";
	std::ifstream fp(filename, std::ios::in | std::ios::binary);
	if(not fp.good()){
		std::ostringstream os;
	os<< "Cannot open \"" << filename << "\": " << std::strerror(errno) <<".";
	//throw std::runtime_error(os.str());
	return "";
	}
	std::cout<<"\nCheck 6\n";
	constexpr const std::size_t buffer_size { 1<<12};
	char buffer[buffer_size];
	unsigned char hash[SHA256_DIGEST_LENGTH]= {0};

	SHA256_CTX ctx;
	std::cout<<filename;
	SHA256_Init(&ctx);
	std::cout<<"\nCheck 7\n";
	if(IsEmpty(filename)){
		std::cout<<"\nMagicCheck\n";
		return "";
	}
	while(fp.good()){
		fp.read(buffer,buffer_size);
		SHA256_Update(&ctx, buffer, fp.gcount());

	}
	std::cout<<"\nCheck 8\n";
	SHA256_Final(hash, &ctx);
	fp.close();
	std::ostringstream os;
	os<< std::hex << std::setfill('0');
	for (int i = 0 ; i< SHA256_DIGEST_LENGTH; ++i){
		os<<std::setw(2) <<static_cast<unsigned int>(hash[i]);

	}
	return os.str();
}
