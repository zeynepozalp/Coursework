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

import java.util.Map          ;
import java.util.Date         ;
import java.util.Random       ;
import java.util.HashMap      ;
import java.io.FileWriter     ;
import java.io.BufferedWriter ;

//***************************************************************************************************************************************************




//**************************************************************************************************************************************************/

public class ImageDescriptionGenerator
{
  //=================================================================================================================================================

  public int                     width            =  400            ;
  public int                     height           =  300            ;
  public int                     canvasRed        =  255            ;
  public int                     canvasGreen      =  255            ;
  public int                     canvasBlue       =  255            ;
  public int                     randomSidesMax   =   36            ;
  public int                     randomLengthMax  =  200            ;
  public int                     numberOfCommands =  250            ;
  public String                  artistName       = "Selim Temizer" ;
  public String                  artworkName      = "Random Art"    ;
  public String                  tidFileName      = "RandomArt"     ;
  public String                  ppmFileName      = "RandomArt"     ;
  public Map< String , Integer > commandProbabilities               ;

  //-------------------------------------------------------------------------------------------------------------------------------------------------

  private       Date             now                                ;
  private       BufferedWriter   file                               ;
  private final Random           random                             ;

  //=================================================================================================================================================

  public ImageDescriptionGenerator ()
  {
    random               = new Random   () ;
    commandProbabilities = new HashMap<>() ;

    commandProbabilities.put( "SetColor"  , 28 ) ;
    commandProbabilities.put( "Point"     , 12 ) ;
    commandProbabilities.put( "Line"      , 12 ) ;
    commandProbabilities.put( "Arc"       , 12 ) ;
    commandProbabilities.put( "Rectangle" , 12 ) ;
    commandProbabilities.put( "Polygon"   , 12 ) ;
    commandProbabilities.put( "Fill"      , 12 ) ;
  }

  //=================================================================================================================================================

  private int randomInt ( int minInclusive , int maxInclusive )  { return minInclusive + random.nextInt( maxInclusive - minInclusive + 1 ) ; }

  //=================================================================================================================================================

  private int randomColor  ()  { return randomInt( 0 , 255             ) ; }
  private int randomRow    ()  { return randomInt( 0 , height - 1      ) ; }
  private int randomCol    ()  { return randomInt( 0 , width  - 1      ) ; }
  private int randomDegree ()  { return randomInt( 0 , 359             ) ; }
  private int randomLength ()  { return randomInt( 1 , randomLengthMax ) ; }
  private int randomSides  ()  { return randomInt( 3 , randomSidesMax  ) ; }

  //=================================================================================================================================================

  public int commandProbabilitiesSum ()
  {
    int sum = 0 ;

    for ( Map.Entry< String , Integer > entry : commandProbabilities.entrySet() )  { sum += entry.getValue() ; }

    return sum ;
  }

  //=================================================================================================================================================

  public void imageBegin () throws Exception
  {
    file.write( String.format( "#------------------------------------------------------------------------------%n"   ) ) ;
    file.write( String.format( "# Created by Image Description Generator v1.0 (Selim Temizer)%n"                     ) ) ;
    file.write( String.format( "# %s%n"                                       , now                                  ) ) ;
    file.write( String.format( "#------------------------------------------------------------------------------%n"   ) ) ;
    file.write( String.format( "# Artist                        : %s%n"       , artistName                           ) ) ;
    file.write( String.format( "# Artwork                       : %s%n"       , artworkName                          ) ) ;
    file.write( String.format( "# TIDFile                       : %s.tid%n"   , tidFileName                          ) ) ;
    file.write( String.format( "# PPMFile                       : %s.ppm%n"   , ppmFileName                          ) ) ;
    file.write( String.format( "# Width                         : %d%n"       , width                                ) ) ;
    file.write( String.format( "# Height                        : %d%n"       , height                               ) ) ;
    file.write( String.format( "# Canvas Color                  : %d %d %d%n" , canvasRed , canvasGreen , canvasBlue ) ) ;
    file.write( String.format( "# Maximum Sides  (Arc, Polygon) : %d%n"       , randomSidesMax                       ) ) ;
    file.write( String.format( "# Maximum Length (Radius, Edge) : %d%n"       , randomLengthMax                      ) ) ;
    file.write( String.format( "# Number of Commands            : %d%n"       , numberOfCommands                     ) ) ;
    file.write( String.format( "#%n"                                                                                 ) ) ;
    file.write( String.format( "# Command Probabilities%n"                                                           ) ) ;
    file.write( String.format( "# ---------------------%n"                                                           ) ) ;
    file.write( String.format( "# SetColor  : %d%n" , commandProbabilities.get( "SetColor"  )                        ) ) ;
    file.write( String.format( "# Point     : %d%n" , commandProbabilities.get( "Point"     )                        ) ) ;
    file.write( String.format( "# Line      : %d%n" , commandProbabilities.get( "Line"      )                        ) ) ;
    file.write( String.format( "# Arc       : %d%n" , commandProbabilities.get( "Arc"       )                        ) ) ;
    file.write( String.format( "# Rectangle : %d%n" , commandProbabilities.get( "Rectangle" )                        ) ) ;
    file.write( String.format( "# Polygon   : %d%n" , commandProbabilities.get( "Polygon"   )                        ) ) ;
    file.write( String.format( "# Fill      : %d%n" , commandProbabilities.get( "Fill"      )                        ) ) ;
    file.write( String.format( "# Total     : %d%n" , commandProbabilitiesSum ()                                     ) ) ;
    file.write( String.format( "#------------------------------------------------------------------------------%n%n" ) ) ;

    file.write( String.format( "Image %d %d %s.ppm%n" , width , height , ppmFileName                                 ) ) ;
    file.write( String.format( "SetColor %d %d %d%n"  , canvasRed , canvasGreen , canvasBlue                         ) ) ;
    file.write( String.format( "Clear%n%n"                                                                           ) ) ;
  }

  //=================================================================================================================================================

  public void imageEnd () throws Exception
  {
    file.write( String.format( "%n#------------------------------------------------------------------------------%n" ) ) ;
  }

  //=================================================================================================================================================

  public void commandSetColor () throws Exception
  {
    file.write( String.format( "SetColor %d %d %d%n" , randomColor() , randomColor() , randomColor() ) ) ;
  }

  //=================================================================================================================================================

  public void commandPoint () throws Exception
  {
    file.write( String.format( "Point %d %d%n" , randomRow() , randomCol() ) ) ;
  }

  //=================================================================================================================================================

  public void commandLine () throws Exception
  {
    file.write( String.format( "Line %d %d %d %d%n" , randomRow() , randomCol() , randomRow() , randomCol() ) ) ;
  }

  //=================================================================================================================================================

  public void commandArc () throws Exception
  {
    file.write( String.format( "Arc %d %d %d %d %d %d%n" ,
                               randomRow() , randomCol() , randomDegree() , randomDegree() , randomLength() , randomSides() ) ) ;
  }

  //=================================================================================================================================================

  public void commandRectangle () throws Exception
  {
    file.write( String.format( "Rectangle %d %d %d %d%n" , randomRow() , randomCol() , randomLength() , randomLength() ) ) ;
  }

  //=================================================================================================================================================

  public void commandPolygon () throws Exception
  {
    file.write( String.format( "Polygon %d %d %d %d%n" , randomRow() , randomCol() , randomLength() , randomSides() ) ) ;
  }

  //=================================================================================================================================================

  public void commandFill () throws Exception
  {
    file.write( String.format( "Fill %d %d%n" , randomRow() , randomCol() ) ) ;
  }

  //=================================================================================================================================================

  public void generate () throws Exception
  {
    now  = new Date()                                                   ;
    file = new BufferedWriter( new FileWriter( tidFileName + ".tid" ) ) ;

    int probabilitySum = commandProbabilitiesSum() ;

    imageBegin() ;

    for ( int i = 0 ; i < numberOfCommands ; i++ )
    {
      int r   = randomInt( 1 , probabilitySum ) ;
      int sum = 0                               ;

      sum += commandProbabilities.get( "SetColor"  ) ;  if ( r <= sum )  { commandSetColor () ;  continue ; }
      sum += commandProbabilities.get( "Point"     ) ;  if ( r <= sum )  { commandPoint    () ;  continue ; }
      sum += commandProbabilities.get( "Line"      ) ;  if ( r <= sum )  { commandLine     () ;  continue ; }
      sum += commandProbabilities.get( "Arc"       ) ;  if ( r <= sum )  { commandArc      () ;  continue ; }
      sum += commandProbabilities.get( "Rectangle" ) ;  if ( r <= sum )  { commandRectangle() ;  continue ; }
      sum += commandProbabilities.get( "Polygon"   ) ;  if ( r <= sum )  { commandPolygon  () ;  continue ; }
      sum += commandProbabilities.get( "Fill"      ) ;  if ( r <= sum )  { commandFill     () ;  continue ; }
    }

    imageEnd() ;

    file.close() ;
  }

  //=================================================================================================================================================

  public static void main ( String[] args ) throws Exception
  {
    ImageDescriptionGenerator generator = new ImageDescriptionGenerator() ;

    generator.generate() ;
  }

  //=================================================================================================================================================
}

//***************************************************************************************************************************************************
