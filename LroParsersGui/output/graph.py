import networkx as nx
import pylab as plt
import json
import argparse


def get_parameter():
    parser = argparse.ArgumentParser()
    parser.add_argument('--input', '-i', type=str, default='./project.json', help="input file path")
    args = parser.parse_args()
    return args


def read_json(args: argparse.Namespace):
    f = open(args.input)
    jfile = json.loads(f.read())
    G = nx.DiGraph()
    List = []
    Node = []
    for node in jfile.keys():
        G.add_node(node[1:])
        Node.append(node[1:])
    for key in jfile.keys():
        sub = jfile[key]['data'].split(' ')
        if len(sub)< 2:
            continue
        List.append((sub[0], key[1:], sub[1]))
    
    
    
    G.add_weighted_edges_from(List)
    
    plt.rc('font', size=16)
    pos = nx.shell_layout(G)
    w = nx.get_edge_attributes(G, 'weight')
    nx.draw(G, pos, with_labels=True, node_color='r')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=w)
    plt.savefig("test.png")


def container(content: str):
    sub_strs = content.split(';')

    new_strs = []
    for value in sub_strs:
        if value != '':
            new_strs.append(value)
    return new_strs


if __name__ == "__main__":
    read_json(get_parameter())
