
import pandas as pd
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import sys, getopt
from math import sqrt
import os

def main(argv):
   if len(sys.argv) != 2:
      sys.exit(2)
data_file = sys.argv[1]
file_name=os.path.splitext(os.path.basename(data_file))[0]+'.jpg'
if __name__ == "__main__":
   main(sys.argv[1:])
data_df = pd.read_csv(data_file, header=None)
dim = int(sqrt(len(data_df[2])))
Y= np.linspace(min(data_df[0].values),max(data_df[0].values),dim) 
X= np.linspace(min(data_df[1].values),max(data_df[1].values),dim) 
Z=np.reshape(data_df[2],(dim,dim)).T

plt.pcolormesh(X,Y,Z,cmap=plt.cm.hot)
plt.title('Visualization of data in 2D')
plt.colorbar()
plt.savefig(file_name)  
plt.close()
