#pragma once
#include"../utils/common_include.h"
#include"../utils/utils.h"
#include"../utils/kernel_function.h"
namespace u2net
{
    class U2NET
    {
    public:
        U2NET(const utils::InitParameter& param);
        ~U2NET();

    public:
        bool init(const std::vector<unsigned char>& trtFile);
        void check();
        void preprocess(const std::vector<cv::Mat>& imgsBatch);
        bool infer();
        void postprocess(const std::vector<cv::Mat>& imgsBatch);
        void showMask(const std::vector<cv::Mat>& imgsBatch, const int& cvDelayTime);
        void saveMask(const std::vector<cv::Mat>& imgsBatch, const std::string& savePath, const int& batchSize, const int& batchi);
        void reset();

    //public:
        //std::vector<std::vector<utils::Box>> getObjectss() const;

    private:
        std::shared_ptr<nvinfer1::ICudaEngine> m_engine;
        std::unique_ptr<nvinfer1::IExecutionContext> m_context;

        //private:
    protected:
        utils::InitParameter m_param;
        nvinfer1::Dims m_output_dims;  // (1, 25200, 85, 0, 0...)
        int m_output_area; // 1 * 25200 * 85
        //int m_total_objects; // 25200
        std::vector<std::vector<utils::Box>> m_objectss;

        
        utils::AffineMat m_dst2src; // 2*3, (m_param.dst_h, m_param.dst_w) to (m_param.src_h, m_param.src_w) 
        utils::AffineMat m_src2dst; // 2*3

        // input
        float* m_input_src_device;
        float* m_input_resize_device;
        float* m_input_rgb_device;
        float* m_input_norm_device;
        float* m_input_hwc_device;
     
        float* m_max_val_device;
        float* m_min_val_device;

        // output
        float* m_output_src_device; // malloc in init()
        float* m_output_resize_device; 
        float* m_output_resize_host; 
        float* m_output_mask_host; 
       
    };
}

// element = element / max
void u2netDivMaxDevice(const int& batchSize, float* src, int srcWidth, int srcHeight, int channel, float* maxVals);

// element = [255 * (element - min)] / (max - min)
void u2netNormPredDevice(const int& batchSize, float* src, int srcWidth, int srcHeight, float scale, float* minVals, float* maxVals);