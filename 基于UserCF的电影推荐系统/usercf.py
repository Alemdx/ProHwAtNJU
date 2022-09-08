import pandas as pd
from numpy import genfromtxt
import numpy as np
import math

# 文件读取
path1='/content/drive/MyDrive/Colab Notebooks/movies.csv'
path2='/content/drive/MyDrive/Colab Notebooks/ratings.csv'
path3='/content/drive/MyDrive/Colab Notebooks/tags.csv'
movies=pd.read_csv(path1)
ratings=pd.read_csv(path2)
tags=pd.read_csv(path3)

# 数据预处理部分
##将'movies'和'ratings'通过id进行链接
data=pd.merge(movies,ratings,on='movieId')
computed=data[['userId','rating','movieId','title']].sort_values('userId')
##读取computed数据，这里之前已经以csv的格式写入了colab中
file=open('/content/drive/MyDrive/Colab Notebooks/computed.csv')
##定义字典 数据格式userid：[movieid1,movieid2,...]
dict={}
for line in file.readlines():
  ###注意这里的strip()是去掉title末尾的'/0'
  line=line.strip().split(',')
  if not line[0] in dict.keys():
    dict[line[0]]=list(line[2])
  else:
    dict[line[0]].append(line[2])


del dict['userId']#删除key为userid的键值对

# 定义余弦相似度
def cosSimilarity(train):
  w=np.zeros([len(train.keys())+1,len(train.keys())+1])  #np创建一个二维0数组 大小为610
  for key1 in train.keys():
    for key2 in train.keys():
      # print(w[int(key1)][int(key2)])
      if (key1!=key2)and(len(set(train[key1])&set(train[key2]))):#键不相同且两个值有交集
        w[int(key1)][int(key2)]=len(set(train[key1])&set(train[key2]))/math.sqrt(len(train[key1])*len(train[key2]))
  return w

# 得到用户之间的相似度矩阵
t=cosSimilarity(dict)
#找出与用户i相似度最高的用户j
#对用户相似矩阵进行两重遍历
def finduser(train):
  y=np.zeros((611,),dtype=np.int) 
  temp=0
  index=0
  for i in range(611):
    for k in range(611):
      if train[i][k]>temp:
        temp=train[i][k]
        index=k
    y[i]=index
    temp=0
    index=0
  return y


s=finduser(t)
path='/content/drive/MyDrive/Colab Notebooks/computed.csv'
file_1 = open(path)
data = file_1.read().split('\n')
data = data[1:]



# 找出s[i]看过评分最高的电影 但是i用户尚未看过
def findmovieid(train):
  ls=np.zeros(611)
  for i in range(1,611):   #遍历610名用户
    t=set(dict[str(train[i])])-set(dict[str(i)]) #两个用户的差集
    score=0
    for j in range(0,100836):
      a=data[j].split(',')
      if a[2] in t and float(a[1])>float(score): #如果电影在该差集中且评分最高
        score=float(a[1])
        ls[i]=a[2]
    score=0   
  return ls


v=findmovieid(s)
#任意的多组列表
a=range(1,611)
v=np.delete(v,0)    
#文件写入
dataframe = pd.DataFrame({'uerid':a,'movid':v})
dataframe.to_csv("/content/drive/MyDrive/Colab Notebooks/movie3.csv",index=False,sep=',')
