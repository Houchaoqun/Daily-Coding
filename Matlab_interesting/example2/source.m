% ѧϰһ��Բ
d = sqrt(5) * randn(200, 2);
idx = d(:,1) .^ 2 + d(:,2) .^ 2 < 4;
d1 = d(idx, :);
d0 = d(~idx, :);

% ѵ�� RBF SVM 
model = svmtrain([zeros(size(d0,1),1); ones(size(d1,1),1)], [d0; d1]);

% ��������
visualize2DModel([-5 5],[-5 5], 0.1,...
    @(d)(svmpredict(zeros(size(d,1),1), d, model)),...
    [1,0.7,0.7; 0.7,0.7,1;]); % ǳ���ǳ��ɫ

% �����ݵ�
hold on;
scatter(d0(:,1), d0(:, 2), 12*ones(size(d0,1),1), 'filled', 'MarkerFaceColor', 'red');
hold on;
scatter(d1(:,1), d1(:, 2), 12*ones(size(d1,1),1), 'filled', 'MarkerFaceColor', 'blue');

