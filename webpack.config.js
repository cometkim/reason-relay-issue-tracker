const fs = require('fs');
const path = require('path');
const url = require('url');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const InterpolateHtmlPlugin = require('react-dev-utils/InterpolateHtmlPlugin');
const MiniCssExtractPlugin = require('mini-css-extract-plugin');
const webpack = require('webpack');
const { homepage } = require(`${process.cwd()}/package.json`);

const publicUrl = process.env.PUBLIC_URL || homepage;
const isProduction = process.env.NODE_ENV === 'production';
const isDevelopment = !isProduction;
const appDirectory = fs.realpathSync(process.cwd());
const paths = {
  appPublic: path.resolve(appDirectory, 'public'),
  appBuild: path.resolve(appDirectory, 'build'),
  appHtml: path.resolve(appDirectory, 'public/index.html'),
  appEntry: path.resolve(appDirectory, 'src/Index.bs.js'),
};

module.exports = {
  entry: paths.appEntry,
  mode: isProduction ? 'production' : 'development',
  devtool: isProduction ? 'source-map' : 'cheap-module-source-map',
  output: {
    path: isProduction ? paths.appBuild : undefined,
    publicPath: publicUrl ? url.parse(publicUrl).pathname : '/',
    filename: isProduction
      ? 'static/js/[name].[contenthash:8].js'
      : 'static/js/bundle.js',
    chunkFilename: isProduction
      ? 'static/js/[name].[contenthash:8].chunk.js'
      : 'static/js/[name].chunk.js',
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          isDevelopment && 'style-loader',
          isProduction && {
            loader: MiniCssExtractPlugin.loader,
          },
          {
            loader: 'css-loader',
            options: {
              importLoaders: 1,
              sourceMap: isProduction,
            },
          },
        ].filter(Boolean),
      },
    ],
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: paths.appHtml,
      inject: true,
      ...isProduction && {
        minify: {
          removeComments: true,
          collapseWhitespace: true,
          removeRedundantAttributes: true,
          useShortDoctype: true,
          removeEmptyAttributes: true,
          removeStyleLinkTypeAttributes: true,
          keepClosingSlash: true,
          minifyJS: true,
          minifyCSS: true,
          minifyURLs: true,
        },
      },
    }),
    new InterpolateHtmlPlugin(HtmlWebpackPlugin, {
      ...process.env,
      PUBLIC_URL: publicUrl,
    }),
    new webpack.DefinePlugin({
      ...process.env,
      __DEV__: JSON.stringify(isDevelopment),
    }),
    isProduction && new MiniCssExtractPlugin({
      filename: 'static/css/[name].[contenthash:8].css',
      chunkFilename: 'static/css/[name].[contenthash:8].chunk.css',
    }),
  ].filter(Boolean),
  devServer: {
    compress: true,
    contentBase: paths.appPublic,
    publicPath: '/',
    port: process.env.PORT || 8000,
    historyApiFallback: true,
    hot: true,
  },
};
