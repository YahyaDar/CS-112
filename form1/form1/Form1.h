#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

namespace CppCLRWinFormsProject {

    using namespace std;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Form1
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
    private:
        System::String^ filename;
    public:
        Form1(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::ComboBox^ comboBox1;

    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label8;


    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(366, 36);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(86, 21);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Calculate";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(178, 186);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(40, 13);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Result: ";
            // 
            // comboBox1
            // 
            this->comboBox1->FormattingEnabled = true;
            this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
                L"example1-10x5.txt", L"example1-20x10.txt", L"example3-50x100.txt",
                    L"example3-20x10.txt", L"example3-10x5.txt", L"example2-200x50.txt", L"example2-50x100.txt", L"example1-50x100.txt", L"example1-200x50.txt",
                    L"example2-10x5.txt", L"example2-20x10.txt", L"example3-200x50.txt"
            });
            this->comboBox1->Location = System::Drawing::Point(237, 36);
            this->comboBox1->Name = L"comboBox1";
            this->comboBox1->Size = System::Drawing::Size(121, 21);
            this->comboBox1->TabIndex = 2;
            this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(237, 186);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(215, 44);
            this->textBox1->TabIndex = 4;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(178, 86);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(52, 13);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Filename: ";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(178, 99);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(117, 13);
            this->label4->TabIndex = 6;
            this->label4->Text = L"Number of Polynomials: ";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(178, 112);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(105, 13);
            this->label5->TabIndex = 7;
            this->label5->Text = L"Number of Variables: ";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(178, 125);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(107, 13);
            this->label6->TabIndex = 8;
            this->label6->Text = L"Data Structure Used: ";
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Location = System::Drawing::Point(178, 138);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(74, 13);
            this->label7->TabIndex = 9;
            this->label7->Text = L"Time Elapsed: ";
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Location = System::Drawing::Point(178, 151);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(96, 13);
            this->label8->TabIndex = 10;
            this->label8->Text = L"Number of non-0\'s:";
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(682, 280);
            this->Controls->Add(this->label8);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->comboBox1);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->button1);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma endregion

    private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

        if (comboBox1->SelectedItem != nullptr) {
            System::String^ selected = comboBox1->SelectedItem->ToString();
            filename = selected;
            //MessageBox::Show(selected);
        }


    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        clock_t start = clock();
        int** Polynomials = nullptr;
        int numPolynomials, numVariables;
        string stdFilename;
        for (int i = 0; i < filename->Length; i++) {
            stdFilename.push_back(static_cast<char>(filename[i]));
        }
        ifstream file(stdFilename);
        if (file.is_open()) {
            file >> numPolynomials >> numVariables;
            // Allocating memory for the polynomials
            Polynomials = new int* [numPolynomials];

            for (int i = 0; i < numPolynomials; i++) {
                Polynomials[i] = new int[numVariables];
                for (int j = 0; j < numVariables; j++) {
                    file >> Polynomials[i][j];
                }
            }
            file.close();
        }
        else {
            MessageBox::Show("Error in opening the file");
            return; // Return after showing the error message
        }

        int* result = new int[numVariables](); // Initialize to zeros

        for (int i = 0; i < numPolynomials; i++) {
            for (int j = 0; j < numVariables; j++) {
                result[j] += Polynomials[i][j];
            }
        }

        int count = 0;//number of 0's
        for (int i = 0; i < numVariables; i++) {
            if (result[i] != 0) {
                count++;
            }
        }

        clock_t stop = clock();

        double time = double(stop - start) / CLOCKS_PER_SEC;
        ofstream outfile("output.txt");

        if (outfile.is_open()) {
            for (int i = 0; i < numVariables; i++) {
                outfile << result[i] << " ";
            }
            outfile.close();
        }
        else {
            MessageBox::Show("Error in opening the file");
            return; // Return after showing the error message
        }

        // Concatenate the numbers into a string
        System::String^ ot = ""; // Initialize an empty string
        ifstream myfile("output.txt");
        if (myfile.is_open()) {
            int coeff;
            while (myfile >> coeff) {
                ot += System::Convert::ToString(coeff) + " ";
            }
            textBox1->Text = ot;
            myfile.close(); // Close the file after reading
        }
        else {
            MessageBox::Show("Error in opening the file");
            delete[] result; // Free the memory before returning
            for (int i = 0; i < numPolynomials; ++i) {
                delete[] Polynomials[i];
            }
            delete[] Polynomials;
            return; // Return after showing the error message

        }
        label3->Text = "Filename: " + filename;
        label4->Text = "Number of Polynomials: " + numPolynomials;
        label5->Text = "Number of Variables: " + numVariables;
        label6->Text = "Data Structure Used: " + "1D-Array";
        label7->Text = "Time Elapsed: " + time + "s";
        label8->Text = "Number of non-0's: " + count;
        // Free memory
        delete[] result;
        for (int i = 0; i < numPolynomials; ++i) {
            delete[] Polynomials[i];
        }
        delete[] Polynomials;
    }


    };

};
