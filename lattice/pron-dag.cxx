// pron-dag.cxx - Directed Acyclic Graph representing possible pronunciations
// Author: Theppitak Karoonboonyanan <theppitak@gmail.com>
// Created: 2018-05-11

#include "pron-dag.h"

#include <utility>

using namespace std;

/////////////////////
//  class FracDAG  //
/////////////////////

FracDAG::FracDAG()
    : DAG<PronunFrac>()
{
}

FracDAG::FracDAG(FracDAG&& other)
    : DAG<PronunFrac> (move (other))
{
}

///////////////////////
//  class PronunDAG  //
///////////////////////

PronunDAG::PronunDAG()
    : DAG<Syl>()
{
}

PronunDAG::PronunDAG (const std::list<SylString> sylStrings)
    : DAG<Syl>()
{
    for (const auto& sylString : sylStrings) {
        int from = 0;
        for (const auto& syl : sylString) {
            addEdge (from, syl.endPos(), syl);
            from = syl.endPos();
        }
    }
}

FracDAG
PronunDAG::fracDAG() const
{
    FracDAG fDAG;

    for (auto it = outBegin(); it != outEnd(); ++it) {
        fDAG.addEdge (
            it->first, it->second.target,
            PronunFrac (it->second.target, SylString (it->second.edgeVal))
        );
    }

    return fDAG;
}

/*
vi:ts=4:ai:expandtab
*/
