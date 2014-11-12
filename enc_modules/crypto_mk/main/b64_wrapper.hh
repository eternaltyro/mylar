#pragma once

/*
  Base 64 encoding wrappers around the multi-key search and sum.
*/



#include "pbc/pbc.h"
#include <string>
#include <list>
#include "main/multikey.hh"
#include "main/multikey_sum.hh"


class b64mk {
public:

    b64mk();
    ~b64mk();
    
    std::string keygen() const;

    std::string delta(const std::string & fromkey, const std::string & tokey);

    std::string token(const std::string & k, const std::string & word);
    std::string encrypt(const std::string & k, const std::string & word);
    std::string index_enc(const std::string &k, const std::string & word);

    // returns a string that contains strings separated by space
    // where each string is index_enc of a word in ptext
    std::string par_enc(const std::string &k, const std::string & ptext);
    
    std::string adjust(const std::string & tok, const std::string & delta);
    bool match(const std::string & searchtok, const std::string & ciph);


    // TODO: can we not duplicate these with the above? 
	std::string pkeygen() const;
	std::string ppubkey(const std::string &k);
	std::string pencrypt(const std::string &pk, const std::string &word);
	std::string padd(const std::string &pk, const std::string &c1, const std::string &c2);
	std::string pdecrypt(const std::string &k, const std::string &cipher);

private:
    mksearch mk;
    mksum mkp;
};

