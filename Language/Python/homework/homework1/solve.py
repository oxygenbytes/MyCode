import numpy as np
import tensorflow as tf

train_path="train.npy"
train_arr = np.load(train_path)

test_path = "test.npy"
test_arr = np.load(train_path)


xs = train_arr[:,0:1]
ys = train_arr[:,1:2]

xa = test_arr[:,0:1]
ya = test_arr[:,1:2]

X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)


Y_pred = tf.Variable(tf.random_normal([1]), name='bias')
W1 = tf.Variable(tf.random_normal([1]))
W2 = tf.Variable(tf.random_normal([1]))
W3 = tf.Variable(tf.random_normal([1]))
W4 = tf.Variable(tf.random_normal([1]))
W = [Y_pred,W1,W2,W3,W4]
for i in range(1, 5):
    Y_pred = tf.add(tf.multiply(tf.pow(X, i), W[i]), Y_pred)

cost = tf.reduce_mean(tf.pow(Y_pred - Y, 2))

learning_rate = 0.01
optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)

n_epochs = 100
with tf.Session() as sess:

    sess.run(tf.global_variables_initializer())
    print("begin train")

    for epoch_i in range(n_epochs):
        for (x, y) in zip(xs,ys):
            sess.run(optimizer, feed_dict={X: x, Y: y})

        training_cost = sess.run(
            cost, feed_dict={X: xs, Y: ys})
        
        
        print(epoch_i,training_cost)

        if training_cost < 1e-12:
            break
    
    print(sess.run(W))

    print("begin test")
    
    for epoch_i in range(n_epochs//10):
            for (x, y) in zip(xa,ya):
                sess.run(optimizer, feed_dict={X: x, Y: y})

            accuracy = sess.run(
                cost, feed_dict={X: xa, Y: ya})
            print(epoch_i,accuracy)

    print("my test")
    y =sess.run(Y_pred,feed_dict={X:0.23})
    print(y)
