#ifndef _BRUTEHASHER_H
#define _BRUTEHASHER_H

template<typename hashable> class BruteHasher{

public:
	unsigned operator()(const hashable &h){
		unsigned res = 0;
		unsigned char *pc =(unsigned char*)&h;
		for (int k =0;k<sizeof(h);++k)
			res += *pc++;
		return res;
	}
};

#endif
