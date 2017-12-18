function visualize2DModel(xrange, yrange, step, clf, colors)
% �ڶ�άƽ���ϻ�������
% xrange : x ����ķ�Χ [low high]
% yrange : y ����ķ�Χ [low high]
% step   : �ڷ�Χ�ڵĲ�������
% clf    : ������������һ�����ݣ��������У���������� label �������Ƕ��ࣩ
% colors : ��ѡ����ɫ����������һ�� N �� 3 �еľ��󣬴��� N �� RGB ��ɫ

    % ������ʾ��Χ�ڵ����������
    [xs, ys] = meshgrid(xrange(1):step:xrange(2), yrange(1):step:yrange(2));
    xy = [xs(:) ys(:)];

    % �Բ�������з��࣬�õ�������
    dec = clf(xy);
    decMap = reshape(dec, size(xs));
    types = numel(unique(dec));

    if (nargin ~= 5)
        colors = hsv(100);
        idx = randperm(100);
        colors = colors(idx, :);
        colors = colors(1:types, :);
        colors = min(colors + 0.6, 1);
    elseif (size(colors, 1) ~= types)
        error('��ɫ������������');
    end

    imagesc(xrange, yrange, decMap);
    hold on;
    set(gca,'ydir','normal');
    colormap(colors);

    hold off;
end

