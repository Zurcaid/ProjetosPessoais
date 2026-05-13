import math
import random

def Sigmoid(x):
    return 1/(1+pow(math.e, -x))

def Derivative(y):
    return y*(1-y)

class Neuron:
    def __init__(self):
        self.entry = []
        self.weight = []
        self.sum_value = 0
        self.activation_value = 0

    def AddEntry(self, n, w):
        for i in range(n):
            self.entry.append(0)
            if(w==0):
                self.weight.append(w)
            else:
                self.weight.append(random.uniform(-0.5, 0.5))


    def ChangeWeight(self, nw):
        for i in range(len(self.weight)):
            self.weight[int(i)] += nw

    def SumFunction(self):
        self.sum_value = 0
        for i in range(len(self.entry)):
            self.sum_value += self.entry[i]*self.weight[i]

    def StepFunction(self):
        self.activation_value = Sigmoid(self.sum_value)
        if self.sum_value > 1:
            return 0
        else:
            return 1

learning_rate = 0.3
momentum = 0.55
previous_variation = 0
accuracy = 0
epochs = 100000

n1 = Neuron()
n2 = Neuron()
n3 = Neuron()

n4 = Neuron()

node_layer = [[n1,n2,n3],[n4]]

for layer in range(len(node_layer)):
    if(layer==0):
        for n in node_layer[0]:
            n.AddEntry(3, 1)
    else:
        for n in node_layer[layer]:
            n.AddEntry(len(node_layer[layer-1])+1, 1)

xor_test_list = [[0,1,0,1],[0,0,1,1],[0,1,1,0,]]

for e in range(epochs):
    error_list = []
    error_avg = 0
    #delta_list[layer][neuron][case]
    delta_list = []
    #result_list[layer][neuron][case]
    result_list = []
    for i_layer in range(len(node_layer)):
        delta_list.append(list())
        result_list.append(list())
        for j_neuron in range(len(node_layer[i_layer])):
            delta_list[i_layer].append(list())
            result_list[i_layer].append(list())
    for i in range(len(xor_test_list[0])):
        for layer in range(len(node_layer)):
            if(layer==0):
                for n in node_layer[0]:             
                    neuron_pos = node_layer[0].index(n)      
                    n.entry[0] = xor_test_list[0][i]
                    n.entry[1] = xor_test_list[1][i]
                    n.entry[2] = 1
                    n.SumFunction()
                    n.StepFunction()
                    result_list[layer][neuron_pos].append(n.activation_value)                    
            else:
                for n in node_layer[layer]:
                    neuron_pos = node_layer[layer].index(n)
                    for n_previous in range(len(node_layer[layer-1])):
                        n.entry[n_previous] = node_layer[layer-1][n_previous].activation_value
                    n.entry[-1] = 1
                    n.SumFunction()
                    n.StepFunction()
                    result_list[layer][neuron_pos].append(n.activation_value)
                    if(e==epochs-1):
                        print("XOR: ", xor_test_list[-1][i])
                        print("Rede: ", n.activation_value)

    for i in range(len(result_list[-1][0])):
        error_list.append((xor_test_list[-1][i]-result_list[-1][0][i]))
        error_avg += abs(error_list[i])
        delta_list[-1][0].append(Derivative(result_list[-1][0][i])*error_list[i])

    for k_weight in range(len(node_layer[-1][0].weight)-1):
        actual_weight = node_layer[-1][0].weight[k_weight]
        entry_value = 0                
        for l_case in range(len(result_list[-2][k_weight])):

            entry_value += result_list[-2][k_weight][l_case]*delta_list[-1][0][l_case]
        actual_variation = (momentum*previous_variation) + (entry_value*learning_rate)
        #node_layer[-1][0].weight[k_weight] = (actual_weight*momentum)+(entry_value*learning_rate)
        node_layer[-1][0].weight[k_weight] = actual_weight + actual_variation
        previous_variation = actual_variation

    error_avg = error_avg/len(error_list)
    for i_neuron in range(len(result_list[0])):
        for j_case in range(len(result_list[0][i_neuron])):
            delta_list[0][i_neuron].append(Derivative(result_list[0][i_neuron][j_case])*node_layer[1][0].weight[i_neuron]*delta_list[1][0][j_case])

    for i_layer in range(len(node_layer)-2, -1, -1):
        for j_neuron in range(len(node_layer[i_layer])):
            for k_weight in range(len(node_layer[i_layer][j_neuron].weight)-1):
                actual_weight = node_layer[i_layer][j_neuron].weight[k_weight]
                entry_value = 0
                if(i_layer==0):
                    for l_case in range(len(xor_test_list[k_weight])):
                        entry_value += xor_test_list[k_weight][l_case]*delta_list[0][j_neuron][l_case]
                else:
                    for l_case in range(len(result_list[i_layer-1][k_weight])):
                        entry_value += result_list[i_layer-1][k_weight][l_case]*delta_list[i_layer][j_neuron][l_case]
                actual_variation = (momentum*previous_variation) + (entry_value*learning_rate)
                #node_layer[i_layer][j_neuron].weight[k_weight] = (actual_weight*momentum)+(entry_value*learning_rate)
                node_layer[i_layer][j_neuron].weight[k_weight] = actual_weight + actual_variation
                previous_variation = actual_variation


    print("AVG Error: ", error_avg)

wish_to_continue = True
user_answer = "n"


while(wish_to_continue):
    entrada1 = int(input("Digite a primeira entrada (porta XOR): "))
    entrada2 = int(input("Digite a segunda entrada (porta XOR): "))
    for layer in range(len(node_layer)):
        if(layer==0):
            for n in node_layer[0]:             
                neuron_pos = node_layer[0].index(n)      
                n.entry[0] = entrada1
                n.entry[1] = entrada2
                n.entry[2] = 1
                n.SumFunction()
                n.StepFunction()
                result_list[layer][neuron_pos].append(n.activation_value)                    
        else:
            for n in node_layer[layer]:
                neuron_pos = node_layer[layer].index(n)
                for n_previous in range(len(node_layer[layer-1])):
                    n.entry[n_previous] = node_layer[layer-1][n_previous].activation_value
                n.entry[-1] = 1
                n.SumFunction()
                n.StepFunction()
    if(node_layer[-1][0].activation_value > 0.5):
        print(" A saída é 1. \n Certeza de: ", (node_layer[-1][0].activation_value*100))
    else:
        print(" A saída é 0. \n Certeza de: ", (100-(node_layer[-1][0].activation_value*100)))
    
    user_answer = input("Deseja continuar? (s para sim, n para não) ")
    if(user_answer == "n"):
        wish_to_continue = False
        