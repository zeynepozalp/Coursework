//***************************************************************************************************************************************************
//
// Copyright (C) 2018 Selim Temizer.
//
// This program is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
//
//***************************************************************************************************************************************************




//***************************************************************************************************************************************************

public class ImageGeneratorGUI extends javax.swing.JFrame
{
  //=================================================================================================================================================

  private static final long serialVersionUID = -1941303633367554522L ;

  //=================================================================================================================================================

  public ImageDescriptionGenerator description ;

  //=================================================================================================================================================

  public ImageGeneratorGUI ()
  {
    initComponents() ;

    description = new ImageDescriptionGenerator() ;

    tfArtist          .setText(      description.artistName                              ) ;
    tfArtwork         .setText(      description.artworkName                             ) ;
    tfTIDFile         .setText(      description.tidFileName                             ) ;
    tfPPMFile         .setText(      description.ppmFileName                             ) ;
    tfWidth           .setText( "" + description.width                                   ) ;
    tfHeight          .setText( "" + description.height                                  ) ;
    tfCanvasRed       .setText( "" + description.canvasRed                               ) ;
    tfCanvasGreen     .setText( "" + description.canvasGreen                             ) ;
    tfCanvasBlue      .setText( "" + description.canvasBlue                              ) ;

    tfSetColor        .setText( "" + description.commandProbabilities.get( "SetColor"  ) ) ;
    tfPoint           .setText( "" + description.commandProbabilities.get( "Point"     ) ) ;
    tfLine            .setText( "" + description.commandProbabilities.get( "Line"      ) ) ;
    tfArc             .setText( "" + description.commandProbabilities.get( "Arc"       ) ) ;
    tfRectangle       .setText( "" + description.commandProbabilities.get( "Rectangle" ) ) ;
    tfPolygon         .setText( "" + description.commandProbabilities.get( "Polygon"   ) ) ;
    tfFill            .setText( "" + description.commandProbabilities.get( "Fill"      ) ) ;
    tfTotal           .setText( "" + description.commandProbabilitiesSum ()              ) ;

    tfMaximumSides    .setText( "" + description.randomSidesMax                          ) ;
    tfMaximumLength   .setText( "" + description.randomLengthMax                         ) ;
    tfNumberOfCommands.setText( "" + description.numberOfCommands                        ) ;

    if   ( System.getProperty( "os.name" ).toLowerCase().contains( "win" ) )  { tfCompiler.setText(   "TIDCompiler" ) ; }
    else /* Assume Linux */                                                   { tfCompiler.setText( "./TIDCompiler" ) ; }
  }

  //=================================================================================================================================================

  private void updateTotal ()
  {
    int total = 0 ;

    total += Integer.parseInt( tfSetColor .getText().trim() ) ;
    total += Integer.parseInt( tfPoint    .getText().trim() ) ;
    total += Integer.parseInt( tfLine     .getText().trim() ) ;
    total += Integer.parseInt( tfArc      .getText().trim() ) ;
    total += Integer.parseInt( tfRectangle.getText().trim() ) ;
    total += Integer.parseInt( tfPolygon  .getText().trim() ) ;
    total += Integer.parseInt( tfFill     .getText().trim() ) ;

    tfTotal.setText( "" + total ) ;
  }

  //=================================================================================================================================================

  /**
   * This method is called from within the constructor to
   * initialize the form.
   * WARNING: Do NOT modify this code. The content of this method is
   * always regenerated by the Form Editor.
   */
  @SuppressWarnings( "unchecked" )
  // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
  private void initComponents()
  {

    l1 = new javax.swing.JLabel();
    l2 = new javax.swing.JLabel();
    l3 = new javax.swing.JLabel();
    l4 = new javax.swing.JLabel();
    l5 = new javax.swing.JLabel();
    l6 = new javax.swing.JLabel();
    l7 = new javax.swing.JLabel();
    l8 = new javax.swing.JLabel();
    l9 = new javax.swing.JLabel();
    l10 = new javax.swing.JLabel();
    l11 = new javax.swing.JLabel();
    l12 = new javax.swing.JLabel();
    l13 = new javax.swing.JLabel();
    l14 = new javax.swing.JLabel();
    l15 = new javax.swing.JLabel();
    l16 = new javax.swing.JLabel();
    l17 = new javax.swing.JLabel();
    l18 = new javax.swing.JLabel();
    l19 = new javax.swing.JLabel();
    l20 = new javax.swing.JLabel();
    l21 = new javax.swing.JLabel();
    l22 = new javax.swing.JLabel();
    tfArtist = new javax.swing.JTextField();
    tfArtwork = new javax.swing.JTextField();
    tfTIDFile = new javax.swing.JTextField();
    tfPPMFile = new javax.swing.JTextField();
    tfWidth = new javax.swing.JTextField();
    tfHeight = new javax.swing.JTextField();
    tfCanvasRed = new javax.swing.JTextField();
    tfCanvasGreen = new javax.swing.JTextField();
    tfCanvasBlue = new javax.swing.JTextField();
    tfSetColor = new javax.swing.JTextField();
    tfPoint = new javax.swing.JTextField();
    tfLine = new javax.swing.JTextField();
    tfArc = new javax.swing.JTextField();
    tfRectangle = new javax.swing.JTextField();
    tfPolygon = new javax.swing.JTextField();
    tfFill = new javax.swing.JTextField();
    tfTotal = new javax.swing.JTextField();
    s1 = new javax.swing.JSeparator();
    tfMaximumSides = new javax.swing.JTextField();
    tfMaximumLength = new javax.swing.JTextField();
    tfNumberOfCommands = new javax.swing.JTextField();
    bGenerate = new javax.swing.JButton();
    s2 = new javax.swing.JSeparator();
    tfCompiler = new javax.swing.JTextField();
    bProcess = new javax.swing.JButton();

    setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
    setTitle("Image Generator");
    setLocationByPlatform(true);
    setResizable(false);

    l1.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l1.setText("Artist :");

    l2.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l2.setText("Artwork :");

    l3.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l3.setText("TID File :");

    l4.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l4.setText("PPM File :");

    l5.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l5.setText("Width :");

    l6.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l6.setText("Height :");

    l7.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l7.setText("Canvas Red :");

    l8.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l8.setText("Canvas Green :");

    l9.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l9.setText("Canvas Blue :");

    l10.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
    l10.setText("Command Probabilities");

    l11.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l11.setText("SetColor :");

    l12.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l12.setText("Point :");

    l13.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l13.setText("Line :");

    l14.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l14.setText("Arc :");

    l15.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l15.setText("Rectangle :");

    l16.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l16.setText("Polygon :");

    l17.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l17.setText("Fill :");

    l18.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l18.setText("<html><b>Total :</b>");

    l19.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l19.setText("Maximum Sides (Arc, Polygon) :");

    l20.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l20.setText("Maximum Length (Radius, Edge) :");

    l21.setHorizontalAlignment(javax.swing.SwingConstants.TRAILING);
    l21.setText("Number of Commands :");

    l22.setText("Compiler :");

    tfSetColor.addActionListener(new java.awt.event.ActionListener()
    {
      public void actionPerformed(java.awt.event.ActionEvent evt)
      {
        tfSetColorActionPerformed(evt);
      }
    });

    tfPoint.addActionListener(new java.awt.event.ActionListener()
    {
      public void actionPerformed(java.awt.event.ActionEvent evt)
      {
        tfPointActionPerformed(evt);
      }
    });

    tfLine.addActionListener(new java.awt.event.ActionListener()
    {
      public void actionPerformed(java.awt.event.ActionEvent evt)
      {
        tfLineActionPerformed(evt);
      }
    });

    tfArc.addActionListener(new java.awt.event.ActionListener()
    {
      public void actionPerformed(java.awt.event.ActionEvent evt)
      {
        tfArcActionPerformed(evt);
      }
    });

    tfRectangle.addActionListener(new java.awt.event.ActionListener()
    {
      public void actionPerformed(java.awt.event.ActionEvent evt)
      {
        tfRectangleActionPerformed(evt);
      }
    });

    tfPolygon.addActionListener(new java.awt.event.ActionListener()
    {
      public void actionPerformed(java.awt.event.ActionEvent evt)
      {
        tfPolygonActionPerformed(evt);
      }
    });

    tfFill.addActionListener(new java.awt.event.ActionListener()
    {
      public void actionPerformed(java.awt.event.ActionEvent evt)
      {
        tfFillActionPerformed(evt);
      }
    });

    tfTotal.setEditable(false);

    bGenerate.setText("Generate TID");
    bGenerate.addActionListener(new java.awt.event.ActionListener()
    {
      public void actionPerformed(java.awt.event.ActionEvent evt)
      {
        bGenerateActionPerformed(evt);
      }
    });

    bProcess.setText("Process TID");
    bProcess.addActionListener(new java.awt.event.ActionListener()
    {
      public void actionPerformed(java.awt.event.ActionEvent evt)
      {
        bProcessActionPerformed(evt);
      }
    });

    javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
    getContentPane().setLayout(layout);
    layout.setHorizontalGroup(
      layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
      .addGroup(layout.createSequentialGroup()
        .addContainerGap()
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
          .addComponent(s1)
          .addComponent(s2)
          .addGroup(layout.createSequentialGroup()
            .addComponent(l22)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfCompiler)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(bProcess, javax.swing.GroupLayout.PREFERRED_SIZE, 97, javax.swing.GroupLayout.PREFERRED_SIZE))
          .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
              .addGroup(layout.createSequentialGroup()
                .addComponent(l20)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(tfMaximumLength))
              .addGroup(layout.createSequentialGroup()
                .addComponent(l21)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(tfNumberOfCommands))
              .addGroup(layout.createSequentialGroup()
                .addComponent(l19)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(tfMaximumSides)))
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(bGenerate))
          .addGroup(layout.createSequentialGroup()
            .addComponent(l9)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfCanvasBlue, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
            .addComponent(l18, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfTotal))
          .addGroup(layout.createSequentialGroup()
            .addComponent(l1)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfArtist, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
            .addComponent(l10, javax.swing.GroupLayout.DEFAULT_SIZE, 171, Short.MAX_VALUE))
          .addGroup(layout.createSequentialGroup()
            .addComponent(l2)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfArtwork, javax.swing.GroupLayout.DEFAULT_SIZE, 200, Short.MAX_VALUE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
            .addComponent(l11)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfSetColor))
          .addGroup(layout.createSequentialGroup()
            .addComponent(l3)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfTIDFile, javax.swing.GroupLayout.DEFAULT_SIZE, 200, Short.MAX_VALUE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
            .addComponent(l12)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfPoint))
          .addGroup(layout.createSequentialGroup()
            .addComponent(l4)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfPPMFile, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
            .addComponent(l13)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfLine))
          .addGroup(layout.createSequentialGroup()
            .addComponent(l5)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfWidth, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
            .addComponent(l14)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfArc))
          .addGroup(layout.createSequentialGroup()
            .addComponent(l6)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfHeight, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
            .addComponent(l15)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfRectangle))
          .addGroup(layout.createSequentialGroup()
            .addComponent(l7)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfCanvasRed, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
            .addComponent(l16)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfPolygon))
          .addGroup(layout.createSequentialGroup()
            .addComponent(l8)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfCanvasGreen, javax.swing.GroupLayout.PREFERRED_SIZE, 200, javax.swing.GroupLayout.PREFERRED_SIZE)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
            .addComponent(l17)
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addComponent(tfFill)))
        .addContainerGap())
    );

    layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {l1, l2, l3, l4, l5, l6, l7, l8, l9});

    layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {tfArtwork, tfCanvasBlue, tfCanvasGreen, tfCanvasRed, tfHeight, tfPPMFile, tfTIDFile, tfWidth});

    layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {l11, l12, l13, l14, l15, l16, l17, l18});

    layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {l19, l20, l21});

    layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {bGenerate, bProcess});

    layout.setVerticalGroup(
      layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
      .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
        .addContainerGap()
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l1)
          .addComponent(tfArtist, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(l10))
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l2)
          .addComponent(tfArtwork, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(l11)
          .addComponent(tfSetColor, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l3)
          .addComponent(tfTIDFile, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(l12)
          .addComponent(tfPoint, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l4)
          .addComponent(tfPPMFile, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(l13)
          .addComponent(tfLine, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l5)
          .addComponent(tfWidth, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(l14)
          .addComponent(tfArc, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l6)
          .addComponent(tfHeight, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(l15)
          .addComponent(tfRectangle, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l7)
          .addComponent(tfCanvasRed, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(l16)
          .addComponent(tfPolygon, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l8)
          .addComponent(tfCanvasGreen, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(l17)
          .addComponent(tfFill, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l9)
          .addComponent(tfCanvasBlue, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(l18, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(tfTotal, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
        .addComponent(s1, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
          .addGroup(layout.createSequentialGroup()
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
              .addComponent(l19)
              .addComponent(tfMaximumSides, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addGap(9, 9, 9)
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
              .addComponent(l20)
              .addComponent(tfMaximumLength, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
              .addComponent(l21)
              .addComponent(tfNumberOfCommands, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
          .addComponent(bGenerate, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        .addGap(14, 14, 14)
        .addComponent(s2, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
          .addComponent(l22)
          .addComponent(tfCompiler, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
          .addComponent(bProcess))
        .addContainerGap())
    );

    pack();
  }// </editor-fold>//GEN-END:initComponents

  private void bGenerateActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_bGenerateActionPerformed
  {//GEN-HEADEREND:event_bGenerateActionPerformed
    updateTotal() ;

    description.artistName  =                   tfArtist     .getText().trim()   ;
    description.artworkName =                   tfArtwork    .getText().trim()   ;
    description.tidFileName =                   tfTIDFile    .getText().trim()   ;
    description.ppmFileName =                   tfPPMFile    .getText().trim()   ;
    description.width       = Integer.parseInt( tfWidth      .getText().trim() ) ;
    description.height      = Integer.parseInt( tfHeight     .getText().trim() ) ;
    description.canvasRed   = Integer.parseInt( tfCanvasRed  .getText().trim() ) ;
    description.canvasGreen = Integer.parseInt( tfCanvasGreen.getText().trim() ) ;
    description.canvasBlue  = Integer.parseInt( tfCanvasBlue .getText().trim() ) ;

    description.commandProbabilities.put( "SetColor"  , Integer.parseInt( tfSetColor .getText().trim() ) ) ;
    description.commandProbabilities.put( "Point"     , Integer.parseInt( tfPoint    .getText().trim() ) ) ;
    description.commandProbabilities.put( "Line"      , Integer.parseInt( tfLine     .getText().trim() ) ) ;
    description.commandProbabilities.put( "Arc"       , Integer.parseInt( tfArc      .getText().trim() ) ) ;
    description.commandProbabilities.put( "Rectangle" , Integer.parseInt( tfRectangle.getText().trim() ) ) ;
    description.commandProbabilities.put( "Polygon"   , Integer.parseInt( tfPolygon  .getText().trim() ) ) ;
    description.commandProbabilities.put( "Fill"      , Integer.parseInt( tfFill     .getText().trim() ) ) ;

    description.randomSidesMax   = Integer.parseInt( tfMaximumSides    .getText().trim() ) ;
    description.randomLengthMax  = Integer.parseInt( tfMaximumLength   .getText().trim() ) ;
    description.numberOfCommands = Integer.parseInt( tfNumberOfCommands.getText().trim() ) ;

    try { description.generate() ; } catch ( Exception e )  { System.out.println( "Generation Failed!" ) ; }
  }//GEN-LAST:event_bGenerateActionPerformed

  private void bProcessActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_bProcessActionPerformed
  {//GEN-HEADEREND:event_bProcessActionPerformed
    String systemCommand = String.format( "%s %s.tid" , tfCompiler.getText().trim() , tfTIDFile.getText().trim() ) ;

    try { Runtime.getRuntime().exec( systemCommand ) ; } catch ( Exception e )  { System.out.println( "Processing Failed!" ) ; }
  }//GEN-LAST:event_bProcessActionPerformed

  private void tfSetColorActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_tfSetColorActionPerformed
  {//GEN-HEADEREND:event_tfSetColorActionPerformed
    updateTotal() ;
  }//GEN-LAST:event_tfSetColorActionPerformed

  private void tfPointActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_tfPointActionPerformed
  {//GEN-HEADEREND:event_tfPointActionPerformed
    updateTotal() ;
  }//GEN-LAST:event_tfPointActionPerformed

  private void tfLineActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_tfLineActionPerformed
  {//GEN-HEADEREND:event_tfLineActionPerformed
    updateTotal() ;
  }//GEN-LAST:event_tfLineActionPerformed

  private void tfArcActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_tfArcActionPerformed
  {//GEN-HEADEREND:event_tfArcActionPerformed
    updateTotal() ;
  }//GEN-LAST:event_tfArcActionPerformed

  private void tfRectangleActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_tfRectangleActionPerformed
  {//GEN-HEADEREND:event_tfRectangleActionPerformed
    updateTotal() ;
  }//GEN-LAST:event_tfRectangleActionPerformed

  private void tfPolygonActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_tfPolygonActionPerformed
  {//GEN-HEADEREND:event_tfPolygonActionPerformed
    updateTotal() ;
  }//GEN-LAST:event_tfPolygonActionPerformed

  private void tfFillActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_tfFillActionPerformed
  {//GEN-HEADEREND:event_tfFillActionPerformed
    updateTotal() ;
  }//GEN-LAST:event_tfFillActionPerformed

  /**
   * @param args the command line arguments
   */
  public static void main ( String args[] )
  {
    /* Set the Nimbus look and feel */
    //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
    /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html
     */
    try
    {
      for ( javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels() )
      {
        if ( "Windows".equals( info.getName() ) )
        {
          javax.swing.UIManager.setLookAndFeel( info.getClassName() );
          break;
        }
      }
    }
    catch ( ClassNotFoundException ex )
    {
      java.util.logging.Logger.getLogger( ImageGeneratorGUI.class.getName() ).log( java.util.logging.Level.SEVERE , null , ex );
    }
    catch ( InstantiationException ex )
    {
      java.util.logging.Logger.getLogger( ImageGeneratorGUI.class.getName() ).log( java.util.logging.Level.SEVERE , null , ex );
    }
    catch ( IllegalAccessException ex )
    {
      java.util.logging.Logger.getLogger( ImageGeneratorGUI.class.getName() ).log( java.util.logging.Level.SEVERE , null , ex );
    }
    catch ( javax.swing.UnsupportedLookAndFeelException ex )
    {
      java.util.logging.Logger.getLogger( ImageGeneratorGUI.class.getName() ).log( java.util.logging.Level.SEVERE , null , ex );
    }
    //</editor-fold>

    /* Create and display the form */
    java.awt.EventQueue.invokeLater( new Runnable()
    {
      @Override public void run ()
      {
        new ImageGeneratorGUI().setVisible( true ) ;
      }
    } );
  }

  // Variables declaration - do not modify//GEN-BEGIN:variables
  private javax.swing.JButton bGenerate;
  private javax.swing.JButton bProcess;
  private javax.swing.JLabel l1;
  private javax.swing.JLabel l10;
  private javax.swing.JLabel l11;
  private javax.swing.JLabel l12;
  private javax.swing.JLabel l13;
  private javax.swing.JLabel l14;
  private javax.swing.JLabel l15;
  private javax.swing.JLabel l16;
  private javax.swing.JLabel l17;
  private javax.swing.JLabel l18;
  private javax.swing.JLabel l19;
  private javax.swing.JLabel l2;
  private javax.swing.JLabel l20;
  private javax.swing.JLabel l21;
  private javax.swing.JLabel l22;
  private javax.swing.JLabel l3;
  private javax.swing.JLabel l4;
  private javax.swing.JLabel l5;
  private javax.swing.JLabel l6;
  private javax.swing.JLabel l7;
  private javax.swing.JLabel l8;
  private javax.swing.JLabel l9;
  private javax.swing.JSeparator s1;
  private javax.swing.JSeparator s2;
  private javax.swing.JTextField tfArc;
  private javax.swing.JTextField tfArtist;
  private javax.swing.JTextField tfArtwork;
  private javax.swing.JTextField tfCanvasBlue;
  private javax.swing.JTextField tfCanvasGreen;
  private javax.swing.JTextField tfCanvasRed;
  private javax.swing.JTextField tfCompiler;
  private javax.swing.JTextField tfFill;
  private javax.swing.JTextField tfHeight;
  private javax.swing.JTextField tfLine;
  private javax.swing.JTextField tfMaximumLength;
  private javax.swing.JTextField tfMaximumSides;
  private javax.swing.JTextField tfNumberOfCommands;
  private javax.swing.JTextField tfPPMFile;
  private javax.swing.JTextField tfPoint;
  private javax.swing.JTextField tfPolygon;
  private javax.swing.JTextField tfRectangle;
  private javax.swing.JTextField tfSetColor;
  private javax.swing.JTextField tfTIDFile;
  private javax.swing.JTextField tfTotal;
  private javax.swing.JTextField tfWidth;
  // End of variables declaration//GEN-END:variables
}
