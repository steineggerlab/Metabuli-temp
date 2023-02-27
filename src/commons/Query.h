#ifndef METABULI_QUERY_H
#define METABULI_QUERY_H

#include <string>
#include <unordered_map>
#include "NcbiTaxonomy.h"
#include "Match.h"
#include "common.h"
#include <algorithm>

using namespace std;

class Query {
private:

public:
    int queryId;
    int classification;
    float score;
    float coverage;
    int hammingDist;
    int queryLength;
    int queryLength2;
    int kmerCnt;
    bool isClassified;
    bool newSpecies; // 36 byte

    Buffer<Match> matches; // 16 byte

    std::string name;
    std::unordered_map<TaxID,int> taxCnt; // 8 byte per element

    bool operator==(int id) const { return queryId == id;}

    Query(int queryId, int classification, float score, float coverage, int hammingDist, int queryLength,
          int queryLength2, int kmerCnt, bool isClassified, bool newSpecies, std::string name)
            : queryId(queryId), classification(classification), score(score), coverage(coverage),
              hammingDist(hammingDist), queryLength(queryLength), queryLength2(queryLength2), kmerCnt(kmerCnt),
              isClassified(isClassified), newSpecies(newSpecies), name(std::move(name)) {}

    Query() : queryId(0), classification(0), score(0), coverage(0), hammingDist(0), queryLength(0),
              queryLength2(0), kmerCnt(0), isClassified(false), newSpecies(false) {

    }

    void init() {
        queryId = 0;
        classification = 0;
        score = 0;
        coverage = 0;
        hammingDist = 0;
        queryLength = 0;
        queryLength2 = 0;
        kmerCnt = 0;
        isClassified = false;
        newSpecies = false;
        name = "";
        taxCnt.clear();
        matches.startIndexOfReserve = 0;
    }

    void sortMatches() {
        std::sort(matches.buffer, matches.buffer + matches.startIndexOfReserve, Match::sort);
    }

    void classify();


};

#endif //METABULI_QUERY_H
