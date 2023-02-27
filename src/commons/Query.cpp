//
// Created by jaebeom on 2/23/23.
//

#include "Query.h"

void Query::classify() {
    // Sort matches of current query
    sortMatches();

    TaxID selectedTaxon;
//    if (par.printLog) {
//        cout << "# " << currentQuery << " " << queryList[currentQuery].name << endl;
//        for (size_t i = offset; i < end + 1; i++) {
//            cout << genusTaxIdList[matchList[i].targetId] << " " << speciesTaxIdList[matchList[i].targetId] << " " <<
//                 taxIdList[matchList[i].targetId] << " " << matchList[i].position << " " << int(matchList[i].hamming) << endl;
//        }
//    }

    // Get the best genus for current query
    vector<Match> genusMatches;


}
