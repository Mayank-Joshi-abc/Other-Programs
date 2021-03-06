function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);
%size(p)
%size(Theta1)
%size(Theta2)
%size(p)
%size(X)
%size(ones(m,1))
%size([ones(m,1),X])
k = [ones(m,1), X];
k = k';
%size(k);
k2 = sigmoid(Theta1*k);
%size(k2);
k3 = [ones(1,m);k2];
%size(k3);
k4 = sigmoid(Theta2*k3);
%size(k4);
[k5,k6] = max(k4);
%size(k5);
%[k5,k6] = max((sigmoid(Theta2 * [ones(1,5000); sigmoid(Theta1
%*[ones(5000,1), X]')])')');
%[k5,k6] = ;
p = k6';

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%









% =========================================================================


end
