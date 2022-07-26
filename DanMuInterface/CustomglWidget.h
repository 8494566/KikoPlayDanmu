#ifndef CUSTOMGLWIDGET_H
#define CUSTOMGLWIDGET_H

#include <iostream>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>

class CustomGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT
	Q_PROPERTY(QPoint CustomGLWidgetPos READ getCustomGLWidgetPos WRITE setCustomGLWidgetPos)
public:

	enum
	{
		Left_Bottom_X,
		Left_Bottom_Y,
		Right_Bottom_X,
		Right_Bottom_Y,
		Right_Top_X,
		Right_Top_Y,
		Left_Top_X,
		Left_Top_Y,
		Pos_Max
	};

	CustomGLWidget(QWidget* parent = nullptr);
	~CustomGLWidget();

	// 设置实时显示的数据源
	virtual void setImageData(uchar* imageSrc, uint width, uint height);
	virtual void setImageData(const QImage& img);
	virtual void setImageDataPost(int x, int y);

public:
	QPoint getCustomGLWidgetPos();
	void setCustomGLWidgetPos(QPoint pos);

protected:
	// 重写QGLWidget类的接口
	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);

private:
	uchar* m_imageData;           //纹理显示的数据源
	QSize m_imageSize;            //图片尺寸
	QSize m_Ortho2DSize;          //窗口尺寸
	QOpenGLTexture* m_texture;
	GLuint m_textureId;           //纹理对象ID
	int m_vertexPos[Pos_Max]{ 0 };     //窗口坐标
	float m_texturePos[Pos_Max]{ 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f };  //纹理坐标
	QImage m_img;
	QPoint pos;
};

#endif // CUSTOMGLWIDGET_HPP
