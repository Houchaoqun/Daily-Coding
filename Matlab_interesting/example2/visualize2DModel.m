function visualize2DModel(xrange, yrange, step, clf, colors)
% 在二维平面上画分类面
% xrange : x 坐标的范围 [low high]
% yrange : y 坐标的范围 [low high]
% step   : 在范围内的采样步长
% clf    : 函数对象，输入一组数据（按行排列），输出分类 label （可以是多类）
% colors : 可选的颜色参数，传入一个 N 行 3 列的矩阵，代表 N 种 RGB 颜色

    % 生成显示范围内的网格采样点
    [xs, ys] = meshgrid(xrange(1):step:xrange(2), yrange(1):step:yrange(2));
    xy = [xs(:) ys(:)];

    % 对采样点进行分类，得到分类结果
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
        error('颜色和类型数不符');
    end

    imagesc(xrange, yrange, decMap);
    hold on;
    set(gca,'ydir','normal');
    colormap(colors);

    hold off;
end

