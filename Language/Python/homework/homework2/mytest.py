import numpy as np
import tensorflow as tf

train_path='train.npy'
train_arr = np.load(train_path)

test_path = 'test.npy'
test_arr = np.load(train_path)

# print(train_arr)

xs = train_arr[:,0:1]
ys = train_arr[:,1:2]

# print(len(xs))
t1 = []
for i in range(len(xs)):
    t1.append(xs[i,0])

# print(t1)
# print(xs[0])
xa = test_arr[:,0:1]
ya = test_arr[:,1:2]

t2 = []
for i in range(len(xs)):
    t2.append(xa[i,0])

X = tf.placeholder(tf.float32,shape=[None,10],name="X")
Y = tf.placeholder(tf.float32,shape=[None,1],name="Y")


b  = tf.Variable(tf.random_normal([1]), name='bias')
W = tf.Variable(tf.random_normal([10,1]),name="weights")
Y_pred = tf.matmul(X,W) + b

cost = tf.reduce_mean(tf.pow(Y_pred - Y, 2))



learning_rate = 0.01
optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)

n_epochs = 1000
with tf.Session() as sess:

    sess.run(tf.global_variables_initializer())
    print("begin train")

    for epoch_i in range(n_epochs):
        sess.run(optimizer, feed_dict={X: t1, Y: ys})

        training_cost = sess.run(
            cost, feed_dict={X: t1, Y: ys})
        if (epoch_i) % 10 == 0:
            print(epoch_i,training_cost)
        if training_cost < 1e-10:
            break


    print("weight:")
    print(sess.run(W)) 
    print("bias:")
    print(sess.run(b))

    print("begin test")

    for epoch_i in range(n_epochs//10):
        sess.run(optimizer, feed_dict={X: t2, Y: ya})

        accuracy = sess.run(
              cost, feed_dict={X: t2, Y: ya})
        if (epoch_i+1) % 10 == 0:
            print(epoch_i,accuracy)

    print("my test")
   
    y =sess.run(Y_pred,feed_dict={X:[[1,1,1,1,1,1,1,1,1,1]]})
    print(y)

