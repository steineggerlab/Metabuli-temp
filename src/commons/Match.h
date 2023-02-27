#ifndef ADCLASSIFIER2_MATCH_H
#define ADCLASSIFIER2_MATCH_H

#include <iostream>

struct Match { // 16 byte
    Match(){}
    Match(int genusId, int speciesId, uint32_t targetId, int position, uint16_t eachHamming, uint8_t hamming, bool redundancy)
        : genusId(genusId), speciesId(speciesId), targetId(targetId), position(position), rightEndHamming(eachHamming),
        hamming(hamming), redundancy(redundancy) { }
    int genusId; // 4
    int speciesId; // 4
    uint32_t targetId; // 4
    int position; // 4
    uint16_t rightEndHamming; // 2
    uint8_t hamming; // 1
    bool redundancy; // 1

    static bool sort(const Match & a, const Match & b) {
        if (a.genusId < b.genusId) return true;
        else if (a.genusId == b.genusId){
            if (a.speciesId < b.speciesId) return true;
            else if (a.speciesId == b.speciesId) {
                if (a.position < b.position) return true;
                else if (a.position == b.position) {
                    if (a.hamming < b.hamming) return true;
                    else if (a.hamming == b.hamming) {
                        return a.targetId < b.targetId;
                    }
                }
            }
        }
        return false;
    }
};

#endif //ADCLASSIFIER2_MATCH_H
