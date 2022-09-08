import numpy as np
from matplotlib import colors     
from sklearn import svm            
from sklearn.svm import SVC
from sklearn import model_selection
import matplotlib.pyplot as plt
import matplotlib as mpl
#鸢尾花数据集导入
from sklearn import datasets
dataset = datasets.load_iris()#json数据格式
X = dataset['data']
y = dataset['target']
#print(dataset)
#print(X)
#print(y)
#数据去掉第三列
X = X[y!= 2,0:3]
#数据不取第三列
y = y[y!= 2]
#Z-score标准化方法：（x-平均数）/标准差  对数据进行标准化处理
X -= np.mean(X,axis=0)
X /= np.std(X,axis=0,ddof=1)
#print(X)
#把数据分成训练集和测试集 比例为7：3
m = len(X)
d = int(0.7 * m)
X_train,X_test = np.split(X,[d])
y_train,y_test = np.split(y,[d])
#print(X_train,X_test,y_train,y_test)
##前面都相当于数据预处理的部分 下面是SVM模型的创建
model_svm = SVC(C=1,kernel='rbf')
#调用fit函数训练模型  
model_svm.fit(X_train,y_train)
ss = model_svm.score(X_test,y_test)
print('测试集的准确率是：',ss)