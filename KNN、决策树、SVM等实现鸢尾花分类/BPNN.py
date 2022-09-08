import pandas as pd
import numpy as np
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score


# MLPClassifier是神经网络分类器
# train_test_split用来划分测试集和训练集
iris = datasets.load_iris()
iris_feature = iris.data
iris_target = iris.target


# 下面是对分割测试集和训练集
x_train,x_test,y_train,y_test = train_test_split(iris_feature,iris_target,train_size=0.8,random_state=125) 

# 建立BPNN模型
clf = MLPClassifier(solver='adam', alpha=1e-5,hidden_layer_sizes=(3,3), random_state=1,max_iter=100000,) 

# 建立训练模型
clf.fit(x_train, y_train)

# 对结果精度进行测试
score1 = clf.score(x_train,y_train)
print(u'测试集准确度：%.4lf' %score1)
