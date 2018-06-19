#pragma once

#include "int_or_value.hpp"
#include "node.hpp"
#include "workload.hpp"

using namespace std;

namespace mwg {

class workload;
class ForN : public node {
public:
    ForN(YAML::Node&);
    ForN() = delete;
    virtual void execute(shared_ptr<threadState>) override;
    virtual std::pair<std::string, std::string> generateDotGraph() override;
    virtual bsoncxx::document::value getStats(bool withReset) override;
    virtual void setNextNode(unordered_map<string, node*>&, vector<shared_ptr<node>>&) override;

protected:
    node* myNode;
    string myNodeName;
    IntOrValue N;
};
}