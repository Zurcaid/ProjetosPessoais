import math

def Sigmoid(x):
    return 1/(1+pow(math.e, -x))
    
def Derivative(y):
    return y*(1-y)
    
class Neuron:
    entry = []
    weight = []
    sum_value = 0
    activation_value = 0
    
    def AddEntry(self, n):
        for i in range(n):
            self.entry.append(0)
            self.weight.append(0)
        
    def ChangeWeight(self, nw):
        for i in range(len(self.weight)):
            self.weight[int(i)] += nw
            
    def SumFunction(self):
        self.sum_value = 0
        for i in range(len(self.entry)):
            self.sum_value += self.entry[i]*self.weight[i]
            
    def StepFunction(self):
        self.activation_value = Sigmoid(sum_value)
        if sum_value > 1:
            return 0
        else:
            return 1
            
learn_factor = 0.1
accuracy = 0
epochs = 10
       
n0 = Neuron()
n0.AddEntry(2)

and_test_list = [[0,1,0,1],[0,0,1,1],[0,0,0,1]]


for e in range(epochs):
    error_num = 0
    result_list = []
    for i in range(len(and_test_list[0])):
        n0.entry[0] = and_test_list[0][i]
        n0.entry[1] = and_test_list[1][i]
        n0.SumFunction()
        result_list.append(n0.StepFunction())
        print("x0: ", n0.entry[0])
        print("x1: ", n0.entry[1])
        print("s: ", n0.StepFunction())
    print("")
    
    for i in range(len(result_list)):
        error_num += and_test_list[2][i] - result_list[i]
        
    n0.ChangeWeight(error_num*learn_factor)
    accuracy = (len(result_list)-error_num)/len(result_list)

wish_to_continue = True
user_answer = "n"

print(accuracy)

while(wish_to_continue):
    n0.entry[0] = int(input("Digite a primeira entrada do neurônio (porta and): "))
    n0.entry[1] = int(input("Digite a segunda entrada do neurônio (porta and): "))
    n0.SumFunction()
    if(n0.StepFunction() == 1):
        print("A saída é 1")
    else:
        print("A saída é 0")
    user_answer = input("Deseja continuar? (s para sim, n para não) ")
    if(user_answer == "n"):
        wish_to_continue = False
    
