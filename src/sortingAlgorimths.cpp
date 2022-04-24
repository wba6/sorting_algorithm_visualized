//
// Created by william on 4/23/22.
//

#include "sortingAlgorimths.h"
#include <algorithm>
#include <iostream>
void sortingAlgorimths::beginSort(std::vector<rectangle *> &vector )
{
    for(size_t i{0}; i<52;i++ ){
        for(size_t j{i+1}; j<52;j++ ){
            if((-1*vector.at(i)->getDestRect().h) <(-1*vector.at(j)->getDestRect().h)){
                int temp = vector.at(i)->getDestRect().x;
                vector.at(i)->getDestRect().x = vector.at(j)->getDestRect().x;
                vector.at(j)->getDestRect().x = temp;
                iter_swap(vector.begin() + i, vector.begin() + j);
            }
        }
    }


    for(size_t i{0}; i<vector.size();i++ ){
        std::cout<<"sorted numbers :"<<vector.at(i)->getDestRect().x/15<< " at " <<vector.at(i)->getDestRect().h<<std::endl;
    }
}
